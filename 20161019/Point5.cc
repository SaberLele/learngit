 ///
 /// @file    Point.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-10-19 16:38:00
 ///
 
#include <iostream>
using std::cout;
using std::endl;


class Point
{
public:
	Point()
	: _ix(0)
	, _iy(0)
	{
		cout << "Point()" << endl;
	}
	Point(int ix, int iy);

	~Point()
	{
		cout << "~Point()" << endl;
	}

	void print();
private:
	int _ix;
	int _iy;
};



Point::Point(int ix, int iy)
: _ix(ix)
, _iy(iy)
{
	cout << "Point(int,int)" << endl;
}

void Point::print()
{
	cout << "(" << _ix
		 << "," << _iy
		 << ")" << endl;
}

int main(void)
{
	Point(7,8);// 匿名对象
	Point arr[5] = {Point(1,2), Point(3, 4)};
	//Point arr2[2] = {Point(1, 2), Point(3,4)};

	return 0;
}
