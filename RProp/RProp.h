#pragma once
#include "Help.h"


class Net{
private:
	Vector (*grad)(Vector);
	double (*func)(Vector);
	Vector weights;
public:
	Net(Vector (*_grad)(Vector),double (*_func)(Vector));
	Vector getMinPoint(Vector X0);
};