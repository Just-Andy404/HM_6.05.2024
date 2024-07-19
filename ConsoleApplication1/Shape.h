#pragma once
#include <iostream>
using namespace std;

class Shape
{
	string _shape;
public:
	Shape();
	void setShape(string);
	virtual void Show() = 0;						
	virtual int getShapeNum() = 0;
	virtual void Save(FILE*) = 0;						
	virtual void Load(FILE*) = 0;
};

