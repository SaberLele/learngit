 ///
 /// @file    Point2.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-10-19 04:58:07
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Point
{
public:
	Point(int ix,int iy,double & dz);
	Point(const Point & rhs);
	void setx(int ix);
	void print();

private:
	int _ix;
	int _iy;
	int & _ref1;
	double & _ref2;
};

Point::Point(int ix,int iy,double & dz)
:_ix(ix)
,_iy(iy)
, _ref1(_ix)    //引用不能绑定在形参，要绑定在存在的对象上面；所以不能用ix；
, _ref2(dz)
{
	cout << "Point(int,int,double)" << endl;
}

Point::Point(const Point & rhs)
:_ix(rhs._ix)
,_iy(rhs._iy)
,_ref1(rhs._ref1)
,_ref2(rhs._ref2)
{
	cout << "Point(const Point & rhs)" << endl;
}

void Point::setx(int ix)
{
	_ix=ix;
}

void Point::print()
{
	cout << "(" << _ix
		<< "," << _iy
		<< "," << _ref1
		<< "," << _ref2
		<< ")" << endl;
}

int main()
{
	double dz=5.0;
	Point p1(1,2,dz);
	p1.print();

	Point p2(p1);
	p2.print();

	p1.setx(7);
	p1.print();
	p2.print();

	return 0;
}


