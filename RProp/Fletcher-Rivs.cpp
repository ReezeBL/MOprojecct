#include "Fletcher-Rivs.h"
#include <climits>
#include <cmath>

FletcherRivsCalculations::FletcherRivsCalculations(Vector (*Gradient)(Vector), double (*Function)(Vector)){
	this->grad = Gradient;
	this->func = Function;
}

double FletcherRivsCalculations::minimizer(Vector dir){
	const double k = (1.0+sqrt(5))/2.0;
	double b = 1;
	double a = -1;
	
	double p1 = b - (b-a)/k;
	double p2 = a + (b-a)/k; 
	double fz1 = func(_x0 + dir*p1);
	double fz2 = func(_x0 + dir*p2);

	while((b-a) > e){
		if(fz1 < fz2){
			b = p2;
			p1 = b - (b-a)/k;
			p2 = a + (b-a)/k; 
			fz1 = func(_x0 + dir*p1);
			fz2 = func(_x0 + dir*p2);
		}
		else{
			a = p1;
			p1 = b - (b-a)/k;
			p2 = a + (b-a)/k; 
			fz1 = func(_x0 + dir*p1);
			fz2 = func(_x0 + dir*p2);		
		}
	}
	double ans = (b+a)/2.0;
	return ans;
}

Vector FletcherRivsCalculations::getMinPoint(Vector X0){
	this->_x0 = X0;
	while(1){
		Vector r,S;
		r = -grad(_x0);
		S = r;
		_x0 = _x0 + S*minimizer(S);
		if(S.Abs() < e ) return _x0;
		for(int i=0;i<2;i++){
			Vector rp = r;
			r = -grad(_x0);	
			S = r + S*((r*r)/(rp*rp));	
			_x0 = _x0 + S*minimizer(S);
			if(S.Abs() < e) return _x0;
		}
	}
}