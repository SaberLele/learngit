 ///
 /// @file    point.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-10-25 04:11:27
 ///
 
#include <iostream>
using std::cout;
using std::endl;
using std::ostream;

class AnotherPoint
{
	friend class Point;
	friend ostream & operator << (ostream & os, const AnotherPoint & rhs);
	public:
		AnotherPoint(double dx,double dy)
		:_dx(dx)
		,_dy(dy)
		{
			cout << "AnotherPoint(double,double)" << endl; 
		}
	private:
		double _dx;
		double _dy;
};

ostream & operator << (ostream & os, const AnotherPoint & rhs)
{
	os << "(" <<rhs._dx << "," << rhs._dy << ")" << endl;
	return os;
}

class Point
{
	friend ostream & operator << (ostream & os,const Point & rhs);
	public:
		Point(int ix,int iy)
		:_ix(ix)
		,_iy(iy)
		{
			cout << "Point(int,int)" << endl;
		}

		Point(const AnotherPoint & rhs)
		:_ix(rhs._dx)
		,_iy(rhs._dy)
		{
			cout << "Point(const AnotherPoint &)" << endl;
		}

		operator int()
		{
			cout << "operator int()" << endl;
			return _ix;
		}
		operator double()
		{
			cout << "operator double()" << endl;
			return _ix*_iy;
		}
		operator AnotherPoint()
		{
			cout << "operator AnotherPoint()" << endl;
			return AnotherPoint(_ix,_iy);
		}

	private:
		int _ix;
		int _iy;
};
ostream & operator << (ostream & os,const Point & rhs)
{
	os << "(" << rhs._ix << "," << rhs._iy << ")" << endl;
	return os;
}


int main()
{
	AnotherPoint p1(1,2);
	cout << p1 << endl;

	Point p2(3,4);
	cout << p2 << endl;

	p2=p1;
	cout << p2 << endl;
	
	int a=p2;
	cout << "a=" << a << endl;

	double b=p2;
	cout << "b=" << b << endl;

	AnotherPoint ap1(3,4);
	cout << "ap1=" << ap1 << endl;
	return 0;
}
