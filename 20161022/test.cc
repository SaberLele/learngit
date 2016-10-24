 ///
 /// @file    test.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-10-22 00:09:53
 ///

#include "mylog.h" 
#include <iostream>
using std::cout;
using std::endl;

int main()
{
	Mylog* log = Mylog::getInstance();
//	log->error("error test");
	logError("Error test");
	return 0;
}
