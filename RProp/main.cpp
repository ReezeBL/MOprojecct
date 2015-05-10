#include <iostream>
#include <ctime>
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
	setlocale(0,"Russian");
	Vector testVal[4] = {Vector(5,-5),Vector(5,0),Vector(10,10),Vector(20,50)};
	NewtonMethod calcNewton(grad,hess);
	FletcherRivsCalculations calcFletcherRivs(grad,func);
	Armicho calcArmicho(grad,func);
	Net calcRprop(grad);
	cout << "Тестирование метода Ньютона: " << endl;
	for(int i=0;i<4;i++){
		time_t t =  clock();
		Vector res = calcNewton.getMinPoint(testVal[i]);
		t = clock() - t;
		cout << "Точка (" << testVal[i].x << ";" << testVal[i].y << "), найденный минимум - (" << res.x << ";"<< res.y << "), затраченное время: " << t << " мс." << endl;
	}
	cout << "Тестирование алгоритма RProp: " << endl;
	for(int i=0;i<4;i++){
		time_t t =  clock();
		Vector res = calcRprop.getMinPoint(testVal[i]);
		t = clock() - t;
		cout << "Точка (" << testVal[i].x << ";" << testVal[i].y << "), найденный минимум - (" << res.x << ";"<< res.y << "), затраченное время: " << t << " мс." << endl;
	}
	cout << "Тестирование алгоритма Флетчера-Ривса: " << endl;
	for(int i=0;i<4;i++){
		time_t t =  clock();
		Vector res = calcFletcherRivs.getMinPoint(testVal[i]);
		t = clock() - t;
		cout << "Точка (" << testVal[i].x << ";" << testVal[i].y << "), найденный минимум - (" << res.x << ";"<< res.y << "), затраченное время: " << t << " мс." << endl;
	}
	cout << "Тестирование метода градиентного спуска по правилу Армихо: " << endl;
	for(int i=0;i<4;i++){
		time_t t =  clock();
		Vector res = calcArmicho.getMinPoint(testVal[i]);
		t = clock() - t;
		cout  << "Точка (" << testVal[i].x << ";" << testVal[i].y << "), найденный минимум - (" << res.x << ";"<< res.y << "), затраченное время: " << t << " мс." << endl;
	}
}