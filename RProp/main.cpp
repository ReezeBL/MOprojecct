#include <iostream>
#include "Fletcher-Rivs.h"
#include "RProp.h"
#include "Armicho.h"
#include "NewtonMethod.h"
using namespace std;

double func(Vector v){
	return 100*(v.y - v.x*v.x)*(v.y - v.x*v.x) + (1-v.x)*(1-v.x);
}

Vector grad(Vector v){
	return Vector(2*(-1+v.x+200*v.x*v.x*v.x-200*v.x*v.y),200*(v.y - v.x*v.x));
}

Matrix hess(Vector v){
	return Matrix(-400 * v.y + 1200 * v.x * v.x + 2,-400 * v.x,200);
}

int main(){
	NewtonMethod calc(grad,hess);
	Vector res = calc.getMinPoint(Vector (20,50));
	cout << res.x << "  " << res.y << endl;
}