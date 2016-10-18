 ///
 /// @file    point.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-10-18 04:46:18
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Point
{
public:
	Point();
	Point(int ix,int iy); //构造函数可重载
	void print();

private:
	int _ix;
	int _iy;
};

#if 1
Point::Point()
{
	cout << "Point()" << endl;
	_ix=0;
	_iy=0;
}
#endif

Point::Point(int ix,int iy)
{
	cout << "Point(int int)" << endl;
	_ix=ix;
	_iy=iy;
}

void Point::print()
{
	cout << "(" << _ix
		<< "," << _iy
		<< ")" << endl;
}

int main()
{
	Point p1;
	p1.print();
	Point p2(1,2);
	p2.print();
}
		
