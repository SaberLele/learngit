 ///
 /// @file    Line.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-10-19 05:28:24
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Point
{
	public:
		Point(int ix,int iy);
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

void Point::print()
{
	cout << "(" << _ix
		<< "," << _iy
		<< ")" << endl;
}

class Line
{
	public:
		Line(int x1,int x2,int y1,int y2);
		void print();
	private:
		Point _p1;
		Point _p2;
};

Line::Line(int x1,int x2,int y1,int y2)
:_p1(x1,y1)
,_p2(x2,y2)
{
	cout << "Line()" <<endl;
}
void Line::print()
{
	_p1.print();
	cout << "==>";
	_p2.print();
	cout << endl;
}

int main()
{
	Line l1(1,2,3,4);
	l1.print();

	return 0;
}
