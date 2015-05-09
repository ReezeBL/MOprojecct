#include "Help.h"
#include <cmath>

Vector::Vector(){
	x=0;y=0;
}
Vector::Vector(double _x,double _y){
	x=_x;y=_y;
}
Matrix::Matrix(double xx, double xy, double yy){
	this->xx = xx;
	this->xy = xy;
	this->yy = yy;
}
Matrix::Matrix(){
	this->xx = 0;
	this->xy = 0;
	this->yy = 0;
}
Matrix Matrix::getReversed(){
	double tmp = 1 / (xx * yy - xy * xy);
	return Matrix(tmp*yy,-tmp*xy,tmp*xx);
}

double Vector::operator*(Vector const& a){
	return x*a.x + y*a.y;
}

Vector Vector::operator*(double const& a){
	return Vector(a*x,a*y);
}

Vector Vector::operator*(Matrix const& a){
	return Vector(x*a.xx + y*a.xy,x*a.xy + y*a.yy);
}

Vector Vector::operator+(Vector const& a){
	return Vector(x+a.x,y+a.y);
}

Vector Vector::operator-(Vector const& a){
	return Vector(x-a.x,y-a.y);
}

Vector Vector::operator-(){
	return Vector(-x,-y);
}

double Vector::Abs(){
	return sqrt(x*x+y*y);
}