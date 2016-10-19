 ///
 /// @file    Point.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-10-19 04:39:27
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Point
{
	public:
		Point(int ix=0,int iy=0);
		void print();
		void print() const;
		~Point();
		void SetX() const;
		//void SetX();
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

void Point::print() const
{
	cout << "[" << _ix
		<< "," << _iy
		<< "]" << endl;
}

Point::~Point()
{
	_ix=-1;
}

void Point::SetX() const
{
	cout<<"hello" << endl;
}

int main()
{
	Point p1;
	p1.print();

	Point p2(1,2);
	p2.print();

	const Point p3(3,4);
	p3.print();
	p3.SetX();
	p3.~Point();

	return 0;
}
