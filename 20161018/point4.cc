 ///
 /// @file    point4.cc
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
		Point(const Point & rhs);  //复制构造函数
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

Point::Point(const Point & rhs)
:_ix(rhs._ix)
,_iy(rhs._iy)
{
	cout << "Point(const Point & rhs)" <<endl;
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

void func1(Point pt)
{
	pt.print();
}

Point func2()
{
	Point pt(3,2);
	pt.print();
	return pt;
}

int main()
{
#if 0
	Point p1;
	p1.print();

	Point p2(1,2);
	p2.print();
#endif
	func2();
//	func1(p2);

#if 0
	Point p3(p2);
	p3.print();

	Point p4=p2;
	p4.print();
#endif

#if 0
	Point *p3=new Point(5,6);
	p3->print();
	delete(p3);
#endif
	return 0;
}

