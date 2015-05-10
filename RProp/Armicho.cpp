#include "Armicho.h"

Armicho::Armicho(Vector (*Gradient)(Vector), double (*Function)(Vector)){
	this->grad = Gradient;
	this->func = Function;
}

Vector Armicho::getMinPoint(Vector X0){
	this->_x0 = X0;
	while(1){
		Vector r;
		r = -grad(_x0);
		_x0 = _x0 + r*stepic(r);
		if(r.Abs() < e ) return _x0;
	}
}

double Armicho::stepic(Vector dir){
	double l = 1e-2;
	const double e = 0.1;
	const double del = 0.1;
	double f1 = func(_x0 + dir*l);
	double f2 = func(_x0)- e*l*(dir*dir);
	while(f1>f2){
		l = l*del;
		f1 = func(_x0 + dir*l);
		f2 = func(_x0)- e*l*(dir*dir);
	}
	return l;
}