 ///
 /// @file    nest.h
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-10-25 05:59:28
 ///

#ifndef __NEST_H__
#define __NEST_H__
#include <iostream>
using std::cout;
using std::endl;

class Line
{
	class LineImpl;
	public:
		Line(int x1,int y1,int x2,int y2);
		~Line();
		void printLine();
	private:
		LineImpl* _pImpl;
};

#endif
