#pragma once
#include <iostream>
#include <fstream>
#include "Shape.h"
using namespace std;

class Square :public Shape 
{
	int _cordX;
	int _cordY;
	float _sideLength;
	int _shapeNum = 4;
public:
	Square();
	Square(float);
	Square(int, int, float);
	int getShapeNum();
	void Show();
	void Save(FILE*);
	void Load(FILE*);

};