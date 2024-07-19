/*
Создайте абстрактный класс Shape для рисования плоских фигур. Определите виртуальные методы:
■ Show () - вывод на экран информации о фигуре,
■ Save () - сохранение фигуры в файл,
■ Load () - считывание фигуры из файла.
Определите производные классы:
■ Square - квадрат, который характеризуется координатами
левого верхнего угла и длиной стороны;
■ Rectangle - прямоугольник с заданными координатами
верхнего левого угла и размерами;
■ Circle - круг с заданными координатами центра и радиусом;
■ Ellipse - эллипс с заданными координатами верхнего
угла описанного вокруг него прямоугольника со сторонами, параллельными осям координат, и размерами
этого прямоугольника.
Создайте массив фигур, сохраните фигуры в файл, загрузите в другой массив и выведите на экран информацию
о каждой из фигур.
*/

#include <iostream>
using namespace std;
#include "Shape.h"
#include "Circle.h"
#include "Ellipse.h"
#include "Rectangle.h"
#include "Square.h"

int main()
{
	FILE* file;
	const char data[] = "Data.dat";

	Circle shape1(0, 0, 5); 
	Ellipse shape2(2, 2, 5.f, 6.f);
	Rectangle shape3(10, 5, 3.f, 4.f);
	Square shape4(2, 8, 15.5f);
	const int size = 4;
	Shape* arr[size]{ &shape1,&shape2, &shape3, &shape4 };
	cout << "----------------------ARR SHAPE 1-----------------------------" << endl;
	for (int i = 0; i < size; i++)
	{
		arr[i]->Show();
	}


	if (fopen_s(&file, data, "wb") == 0)
	{
		fwrite(&size, sizeof(int), 1, file);
		for (int i = 0; i < size; i++)
		{
			int shapeNum = arr[i]->getShapeNum();
			fwrite(&shapeNum, sizeof(int), 1, file);
			arr[i]->Save(file);

		}
		fclose(file);
	}


	Shape** newArr = nullptr;
	int size2;
	if (fopen_s(&file, data, "rb") == 0)
	{
		fread(&size2, sizeof(int), 1, file);
		newArr = new Shape * [size2];
		for (int i = 0; i < size2; i++)
		{
			int shapeNum;
			fread(&shapeNum, sizeof(int), 1, file);
			if (shapeNum == 1)
			{
				newArr[i] = new Circle();
				newArr[i]->Load(file);
			}
			if (shapeNum == 2)
			{
				newArr[i] = new Ellipse();
				newArr[i]->Load(file);
			}
			if (shapeNum == 3)
			{
				newArr[i] = new Rectangle();
				newArr[i]->Load(file);
			}
			if (shapeNum == 4)
			{
				newArr[i] = new Square();
				newArr[i]->Load(file);
			}

		}
		fclose(file);
	}
	cout << "----------------------ARR SHAPE 2-----------------------------" << endl;
	for (int i = 0; i < size2; i++)
	{
		newArr[i]->Show();
	}
	return 0;
}