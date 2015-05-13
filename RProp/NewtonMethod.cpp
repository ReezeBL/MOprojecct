#include "NewtonMethod.h"

NewtonMethod::NewtonMethod(Vector (*Gradient)(Vector), Matrix (*Hessian)(Vector)){
	this->grad = Gradient;
	this->hess = Hessian;
	this->it = 0;
}

Vector NewtonMethod::getMinPoint(Vector X0){
	this->it = 0;
	this->_x0 = X0;
	Vector r;
	do{
		it++;
		r = grad(_x0);
		Matrix m = hess(_x0).getReversed();
		_x0 = _x0 - m*r;
	}while(r.Abs() > e);
	return _x0;
}