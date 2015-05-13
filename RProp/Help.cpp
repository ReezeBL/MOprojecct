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
double Matrix::Det(){
	return xx*yy - xy*xy;
}
Matrix Matrix::getReversed(){
	double tmp = 1 / (xx * yy - xy * xy);
	return Matrix(tmp*yy,-tmp*xy,tmp*xx);
}

double Vector::operator*(Vector const& a){
	return x*a.x + y*a.y;
}

Vector operator*(Vector const &a, double const& b){
	return Vector(a.x*b,a.y*b);
}

Vector operator*(double const &a, Vector const& b){
	return Vector(a*b.x,a*b.y);
}

Vector operator*(Matrix const &a, Vector const& b){
	return Vector(b.x*a.xx + b.y*a.xy,b.x*a.xy + b.y*a.yy);
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