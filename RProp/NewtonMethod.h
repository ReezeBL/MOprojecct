#pragma once
#include "Help.h"

class NewtonMethod{
public:
	NewtonMethod(Vector (*Gradient)(Vector), Matrix (*Hessian)(Vector));
	Vector getMinPoint(Vector X0);
private:
	Vector (*grad)(Vector);
	Matrix (*hess)(Vector);
	Vector _x0;
	double minimizer(Vector dir);
};