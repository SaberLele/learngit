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
//	Point();
	explicit  //禁止隐式转换
	Point(int ix=0,int iy=0); //构造函数可重载
	void print();

private:
	int _ix;
	int _iy;
};

#if 0
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

	Point p3=5;   //隐式转换
	p3.print();

	return 0;
}
		
