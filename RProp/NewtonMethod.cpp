#include "NewtonMethod.h"

NewtonMethod::NewtonMethod(Vector (*Gradient)(Vector), Matrix (*Hessian)(Vector)){
	this->grad = Gradient;
	this->hess = Hessian;
}

Vector NewtonMethod::getMinPoint(Vector X0){
	this->_x0 = X0;
	Vector r;
	do{
		r = grad(_x0);
		Matrix m = hess(_x0).getReversed();
		_x0 = _x0 - r*m;
	}while(r.Abs() > e);
	return _x0;
}