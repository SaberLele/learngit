 ///
 /// @file    point3.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-10-18 05:34:11
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Point
{
	public:
		Point(int ix=0,int iy=0);
		~Point();
		void print();
	private:
		int _ix;
		int _iy;
};

Point::Point(int ix,int iy)
:_ix(ix)
,_iy(iy)
{
	cout << "Point(int,int)" << endl;
}

Point::~Point()
{
	cout << "~point()" << endl;
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

	Point *p3=new Point(5,6);
	p3->print();
	delete(p3);
	return 0;
}

