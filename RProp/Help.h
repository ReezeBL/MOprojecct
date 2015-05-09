#pragma once
#include <cmath>

struct Matrix;
struct Vector{
	double x, y;
	Vector();
	Vector(double _x,double _y);
	double Abs();
	double operator*(Vector const& a);
	Vector operator*(double const& a);
	Vector operator*(Matrix const& a);
	Vector operator+(Vector const& a);
	Vector operator-(Vector const& a);
	Vector operator-();
};

struct Matrix{
	double xx,xy,yy;
	Matrix();
	Matrix(double xx, double xy, double yy);
	Matrix getReversed();
};

const double e = pow(10,-7);