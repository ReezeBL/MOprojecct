#pragma once
#include "Help.h"

class Armicho{
public:
	Armicho(Vector (*Gradient)(Vector), double (*Function)(Vector));
	Vector getMinPoint(Vector X0);
private:
	Vector (*grad)(Vector);
	double (*func)(Vector);
	Vector _x0;
	double stepic(Vector dir);
};