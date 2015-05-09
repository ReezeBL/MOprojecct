#include "Libs.h"

Vector::Vector(double first,...){
	_m.clear();
	double *p = &first;
	while(p){
		_m.push_back(*p);
		p++;
	}
	_n = _m.size();
}

Vector::Vector(Vector const& a){
	_n = a._n;
	_m.clear();
	for(int i=0;i<_n;i++)
		_m.push_back(a._m[i]);
}

void Vector::EachFunc(double (*func) (double)){
	for(int i=0;i<_n;i++){
		_m[i] = func(_m[i]);
	}
}

double Vector::getEl(int i){
	if(i<_n)
		return _m[i];
	else
		throw new exception("Index out of bonds");
}

double Vector::getAbs(){
	double sum = 0;
	for(int i=0;i<_n;i++){
		sum+= _m[i]*_m[i];
	}
	return sqrt(sum);
}

double& Vector::operator[](int i){
	if(i<_n)
		return _m[i];
	else
		throw new exception("Index out of bonds");
}

Vector Vector::operator+(Vector const&a){
	Vector res = Vector(a);
	for(int i=0;i<_n;i++)
		res[i]+=_m[i];
	return res;
}

double Vector::operator*(Vector const&a){
	double sum = 0;
	for(int i=0;i<_n;i++){
		sum += a._m[i]*_m[i];
	}
	return sum;
}

Vector Vector::operator*(double const&a){
	Vector res = Vector(*this);
	for(int i=0;i<_n;i++)
		res[i]*=a;
	return res;
}