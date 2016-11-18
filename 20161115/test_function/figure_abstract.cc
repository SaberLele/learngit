 ///
 /// @file    abstract.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-05-09 10:05:25
 ///
 
#include <math.h>
#include <iostream>
#include <functional>
using std::cout;
using std::endl;
using std::function;
using std::bind;

const float PI = 3.14159f;

//基于对象的编程方式 -- 封装，组合
//代码复用时使用组合，不使用继承
class Figure
{
	public:
		typedef function<float()> AreaCallback;
		typedef function<void()> DisplayCallback;

	public:
		Figure(AreaCallback ca,DisplayCallback cb)
		:_ca(ca)
		,_cb(cb)
		{}
		
		float runAreaCallback()
		{
			if(_ca)
				return _ca();
			else
				return 0;
		}

		void runDisplayCallback()
		{
			if(_cb)
				_cb();
		}

		void setAreaCallback(AreaCallback ca)
		{
			_ca = ca;
		}
		void setDisplayCallback(DisplayCallback cb)
		{
			_cb=cb;
		}

	private:
		//回调函数 -- 函数名本身也变成了变量
		AreaCallback    _ca;
		DisplayCallback _cb;
};


class Circle
{
public:
	Circle(float fRadius)
	: _fRadius(fRadius)
	{}

	float area()
	{
		return PI * _fRadius * _fRadius;
	}

	void print()
	{
		cout << "圆:";
	}
	
private:
	float _fRadius;
};

class Rectangle
{
public:
	Rectangle(int a, int b)
	: _ia(a)
	, _ib(b)
	{}

	float rectArea()
	{
		return _ia * _ib;
	}

	void rectPrint()
	{
		cout << "矩形:";
	}
	
private:
	int _ia;
	int _ib;
};

class Triangle
{
public:
	Triangle(float a, float b, float c)
	: _ia(a)
	, _ib(b)
	, _ic(c)
	{}

	float triangleArea()
	{
		float p = (_ia + _ib + _ic)/2;
		return sqrt(p *(p -_ia) * (p - _ib) * (p - _ic));
	}

	void trianglePrint()
	{
		cout << "三角形:";
	}
	
private:
	float _ia;
	float _ib;
	float _ic;
};

int main(void)
{
	Circle circle(5);
	Figure fig(bind(&Circle::area, &circle),
			   bind(&Circle::print, &circle));
	fig.runDisplayCallback();
	cout << fig.runAreaCallback() << endl;
	cout << endl;

	Rectangle rect(3,4);
	fig.setAreaCallback(bind(&Rectangle::rectArea, &rect));
	fig.setDisplayCallback(bind(&Rectangle::rectPrint, &rect));
	fig.runDisplayCallback();
	cout << fig.runAreaCallback() << endl;
	cout << endl;

	Triangle tri(3,4,5);
	fig.setAreaCallback(bind(&Triangle::triangleArea, &tri));
	fig.setDisplayCallback(bind(&Triangle::trianglePrint, &tri));
	fig.runDisplayCallback();  
	cout << fig.runAreaCallback() << endl;
	cout << endl;

	return 0;
}
