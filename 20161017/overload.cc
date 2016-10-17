 ///
 /// @file    overload.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-10-17 06:31:37
 ///

#include <stdio.h>
#include <iostream>
using std::cout;
using std::endl;

#ifdef __cplusplus
extern "C"
{
#endif
	int add(int a,int b)
	{
		return a+b;
	}
#ifdef __cplusplus
}
#endif

int add(int a,int b,int c)
{
	return a+b+c;
}

int main()
{
	int a=1,b=2,c=3;
	cout << add(a,b) << endl;
	cout << add(a,b,c) << endl;
	return 0;
}



