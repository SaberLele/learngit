 ///
 /// @file    nest.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-10-25 05:31:57
 ///

#include "nest.h"
#include <iostream>
using std::cout;
using std::endl;

class Line::LineImpl
{
	private:
		class Point
		{
			public:
				Point(int ix=0,int iy=0)
				:_ix(ix)
				,_iy(iy)
				{
				}
				void printPoint();
			private:
				int _ix;
				int _iy;
		};
	public:
		LineImpl(int ix1,int iy1,int ix2,int iy2)
		:_p1(ix1,iy1)
		,_p2(ix2,iy2)
		{
		}
		void printLine()
		{
			_p1.printPoint();
			cout<< "--->" ;
			_p2.printPoint(); 
			cout<< endl;
		}
	private:
		Point _p1;
		Point _p2;
};

void Line::LineImpl::Point::printPoint()
{
	cout << "(" << _ix <<  "," << _iy << ")";
}

Line::Line(int x1, int y1, int x2, int y2)
:_pImpl(new LineImpl(x1,y1,x2,y2))
{
	cout << "Line(int,int,int,int)" << endl;
}

Line::~Line()
{
	delete _pImpl;
	cout << "~Line()" << endl;
}

void Line::printLine()
{
	_pImpl->printLine();
}
