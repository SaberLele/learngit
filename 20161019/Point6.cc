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
		~Point();
		void print();
		void Set(int ix,int iy);
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
	cout << "~Point()" << endl;
}
void Point::print()
{
	cout << "(" << _ix
		<< "," << _iy
		<< ")" << endl;
}

void Point::Set(int ix,int iy)
{
	_ix=ix;
	_iy=iy;
}

int main()
{
	Point *p= new Point[2];
	p[0].print();
	p[1].Set(4,5);
	p[1].print();

	delete [] p;
	p=NULL;

	return 0;
}
