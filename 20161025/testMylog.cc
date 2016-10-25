 ///
 /// @file    testMylog.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-10-24 11:40:03
 ///
 
#include "Mylog.h"
#include <iostream>
#include <sstream>
using std::cout;
using std::endl;

int test(void)
{
	LogInfo("info message");
	LogWarn("warn message");
	LogError("error message");
	LogDebug("debug message");

	return 0;
}


int main(void)
{
	test();


#if 0
	cout << __FILE__ << endl;
	cout << __FUNCTION__ << endl;
	//cout << __func__ << endl;
	//cout << __LINE__ << endl;
#endif
}
