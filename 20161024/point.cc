 ///
 /// @file    point.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-10-24 04:15:28
 ///

#include <math.h>
#include <iostream>
using std::cout;
using std::endl;

class Point
{
	friend float distance(const Point & lhs,const Point &rhs);
	public:
		Point(int ix,int iy)
		:_ix(ix)
		,_iy(iy)
		{
		}
		void print()
		{
			cout << "(" << _ix
				<< "," << _iy
				<< endl;
		}
	private:
		int _ix;
		int _iy;
};

float distance(const Point & lhs,const Point & rhs)
{
	return sqrt((lhs._ix-rhs._ix)*(lhs._ix-rhs._ix)
			 + (lhs._iy-rhs._iy)*(lhs._iy-rhs._iy));
}

int main()
{
	Point pt1(3,4);
	Point pt2(1,2);
	cout << "distance is:" << distance(pt1,pt2) << endl;

	return 0;
}
