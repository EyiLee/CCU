#ifndef MYSHAPE
#define MYSHAPE
#include<iostream>
#include<cmath>

using namespace std;

class MyShape {
		int typeOfShape;
	public:
		MyShape(int);
		virtual double findArea() = 0;
		virtual void showShape() { cout << "Shape is Generic"; }
};

class Rectangle:public MyShape {
		int length, width;
	public:
		Rectangle(int, int);
		virtual double findArea();
		virtual void showShape() { cout << "Shape is Rectangle"; }
};

class Circle:public MyShape {
		int Diameter;
	public:
		Circle(int);
		virtual double findArea();
		virtual void showShape() { cout << "Shape is Circle"; }
};

#endif
