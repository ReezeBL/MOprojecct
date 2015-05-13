#pragma once
#include "Help.h"


class Net{
private:
	Vector (*grad)(Vector);
	Vector weights;	
public:
	int it;
	Net(Vector (*_grad)(Vector));
	Vector getMinPoint(Vector X0);
};