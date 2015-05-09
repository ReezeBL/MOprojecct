#pragma once
#include <vector>;
using namespace std;

class Matrix;
class Vector{
private:
	int _n;
	vector<double> _m;
public:
	Vector(double first, ...);
	Vector(Vector const&);
	void EachFunc(double (*func) (double));
	double getEl(int i);
	double getAbs();
	double& operator[](int i);
	Vector operator+(Vector const&a);
	double operator*(Vector const&a);
	Vector operator*(double const&a);
	Vector operator*(Matrix const&a);
};