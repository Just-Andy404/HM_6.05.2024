#pragma once
#include <iostream>
using namespace std;
#include "Shape.h"
#include <fstream>

class Ellipse :public Shape 
{
	int _cordX;
	int _cordY;
	float _XLength;
	float _YLength;
	int _shapeNum = 2;
public:
	Ellipse();
	Ellipse(float, float);
	Ellipse(int, int, float, float);
	int getShapeNum();
	void Show();
	void Save(FILE*);
	void Load(FILE*);
};