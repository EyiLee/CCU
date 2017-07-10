#include"MyShape.hpp"

MyShape::MyShape(int type) {
	typeOfShape = type;
}

Rectangle::Rectangle(int l, int w):MyShape(1) {
	length = l;
	width = w;
}

double Rectangle::findArea() {
	return length * width;
}

Circle::Circle(int d):MyShape(2) {
	Diameter = d;
}

double Circle::findArea() {
	return (double)Diameter / 2 * (double)Diameter / 2 * M_PI;
}
