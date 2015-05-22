#include "Fletcher-Rivs.h"
#include <climits>
#include <cmath>

FletcherRivsCalculations::FletcherRivsCalculations(Vector (*Gradient)(Vector), double (*Function)(Vector)){
	this->grad = Gradient;
	this->func = Function;
	this->it = 0;
}

double FletcherRivsCalculations::minimizer(Vector dir){
	double b = 1;
	double a = 0;
	 
	do {
		double d = (b-a)/20.0 ;
		double p1 = (a+b)/2.0 - d;
		double p2 = (a+b)/2.0 + d; 
		double fz1 = func(_x0 + dir*p1);
		double fz2 = func(_x0 + dir*p2);

		if(fz1 < fz2)
			b = p2;
		else
			a = p1;	
		
	}
	while((b-a) > e);

	double ans = (b+a)/2.0;
	return ans;
}

Vector FletcherRivsCalculations::getMinPoint(Vector X0){
	this->_x0 = X0;
	this->it = 0;
	while(1){
		it++;
		Vector r,S;
		r = -grad(_x0);
		S = r;
		_x0 = _x0 + minimizer(S)*S;
		if(r.Abs() < e ) return _x0;
		for(int i=0;i<1;i++){
			it++;
			Vector rp = r;
			r = -grad(_x0);	
			S = r + ((r*r)/(rp*rp))*S;	
			_x0 = _x0 + minimizer(S)*S;
			if(r.Abs() < e) return _x0;
		}
	}
}