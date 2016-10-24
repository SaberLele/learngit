 ///
 /// @file    point.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-10-24 04:15:28
 ///

#include <math.h>
#include <iostream>
using std::cout;
using std::endl;

class Point;

class Line
{
	public:
		Line()
		{
		};
		Line(float dis)
		:_dis(dis)
		{
		}

		float distance(const Point & lhs,const Point & rhs);
		void setPoint(Point *pt,int ix,int iy);
		void display() const
		{
			cout << "_dis= " << _dis << endl;
		}
	private:
		float _dis;
};

class Point
{
	friend class Line;
	public:
		Point(int ix,int iy)
		:_ix(ix)
		,_iy(iy)
		{
		}
		void print() const
		{
			cout << "(" << _ix
				<< "," << _iy
				<< ")" << endl;
		}
	private:
		int _ix;
		int _iy;
};

float Line::distance(const Point & lhs,const Point & rhs)
{
	return sqrt((lhs._ix-rhs._ix)*(lhs._ix-rhs._ix)
			 + (lhs._iy-rhs._iy)*(lhs._iy-rhs._iy));
}

void Line::setPoint(Point *pt,int ix,int iy)
{
	pt->_ix=ix;
	pt->_iy=iy;
}

int main()
{
	Line line;
	Point pt1(3,4);
	Point pt2(1,2);
	cout << "distance is:" <<line.distance(pt1,pt2) << endl;

	line.setPoint(&pt1,5,6);
	pt1.print();

	return 0;
}
