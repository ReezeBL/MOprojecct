#pragma once
#include "Help.h"


class Net{
private:
	Vector (*grad)(Vector);
	Vector weights;
public:
	Net(Vector (*_grad)(Vector));
	Vector getMinPoint(Vector X0);
};