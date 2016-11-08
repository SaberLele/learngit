 ///
 /// @file    figure.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-08 04:27:35
 ///

#include <math.h>
#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::shared_ptr;

const float PI=3.14159;

class Figure
{
	public:
		virtual float area()=0;
		virtual void display()=0;
};

class Circle
:public Figure
{
	public:
		Circle(float fRadius)
		:_fRadius(fRadius)
		{}

		float area()
		{
			return PI*_fRadius*_fRadius;
		}

		void display()
		{
			cout << "Circle: ";
		}

		~Circle()
		{
			cout << "~Circle()" << endl;
		}

	private:
		 float _fRadius;

};

class Retangle
:public Figure
{
	public:
		Retangle(float length,float width)
		:_length(length)
		,_width(width)
		{}

		float area()
		{
			return _length*_width;
		}
		void display()
		{
			cout << "Retangle: ";
		}

		~Retangle()
		{
			cout << "~Retangle()" << endl;
		}
	private:
		float _length;
		float _width;
};

class Triangle
:public Figure
{
	public:
		Triangle(float a,float b,float c)
		:_a(a)
		,_b(b)
		,_c(c)
		{}

		float area()
		{
			float p = (_a + _b + _c) / 2;
			return sqrt(p *(p - _a) * (p - _b) * (p - _c));
		}

		void display()
		{
			cout << "Triangle: ";
		}
		~Triangle()
		{
			cout << "~Triangle()" << endl;
		}
	private:
		float _a;
		float _b;
		float _c;
};

void test(shared_ptr<Figure> fig)
{
	fig->display();
	cout << fig->area() << endl;
}

int main()
{
	shared_ptr<Figure> sf1(new Circle(5));
	test(sf1);

	shared_ptr<Figure> sf2(new Retangle(3, 4));
	test(sf2);

	shared_ptr<Figure> sf3(new Triangle(3, 4, 5));
	test(sf3);

	return 0;
}
