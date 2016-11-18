 ///
 /// @file    factory.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-13 04:30:37
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class shape
{
	public:
		virtual void draw() = 0;
};

class Circle
:public shape
{
	public:
		void draw()
		{
			cout << "draw a Circle" << endl;
		}
};
class Square
:public shape
{
	public:
		void draw()
		{
			cout << "draw a Square" << endl;
		}
};
class Rectangle
:public shape
{
	public:
		void draw()
		{
			cout << "draw a Rectangle" << endl;
		}
};

enum shapeType
{
	CIRCLE,
	SQUARE,
	RECTANGLE
};

class shapeFactory
{
	public:
		shape *getShape(shapeType type)
		{
			if(type==CIRCLE)
				return new Circle;
			if(type==SQUARE)
				return new Square;
			if(type==RECTANGLE)
				return new Rectangle;
			return nullptr;
		}
};

int main()
{
	shapeFactory sf;
	shape* pshape=sf.getShape(CIRCLE);
	pshape->draw();

	pshape=sf.getShape(RECTANGLE);
	pshape->draw();

	pshape=sf.getShape(SQUARE);
	pshape->draw();

	return 0;
}
