#include "RProp.h"
#include <cmath>

const double ni = 1.2;
const double nd = 0.5;

double sign(double x){
	if(x!=0)
		return x/abs(x);
	else
		return 0;
}

double max(double a, double b){
	return a > b ? a : b;
}

double min(double a, double b){
	return a > b ? b : a;
}


Net::Net(Vector (*_grad)(Vector)){
	grad = _grad;	
}

Vector Net::getMinPoint(Vector X0){
	weights = X0;
	double dx = 0.5,dy = 0.5;
	double dwx = 0, dwy = 0;
	Vector dp;
	Vector r;
	while(grad(weights).Abs() > e){
		dp = r;
		r = grad(weights);
		//-----------------------------------------------------------------------------
		if(dp.x * r.x > 0){
			dx = dx*ni;
			dwx = -sign(r.x)*dx;
		}
		else if(dp.x * r.x < 0){
			dwx = -dwx;
			dx = dx*nd;
			r.x = 0;
		}
		else{
			dwx = -sign(r.x)*dx;
		}
		//--------------------------------------------------------------------------------
		if(dp.y * r.y > 0){
			dy = dy*ni;
			dwy = -sign(r.y)*dy;
		}
		else if(dp.y * r.y < 0){
			dwy = -dwy;
			dy = dy*nd;
			r.y = 0;
		}
		else{
			dwy = -sign(r.y)*dy;
		}
		//--------------------------------------------------------------------------------
		weights = weights + Vector(dwx,dwy);
	}
	return weights;
}