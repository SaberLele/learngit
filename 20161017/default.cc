 ///
 /// @file    default.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-10-17 06:44:12
 ///
 
#include <iostream>
using std::cout;
using std::endl;

int add(int a,int b=1)
{
	return a+b;
}

int add(int a,int b, int c)
{
	return a+b+c;
}

int main()
{
	int a=10,b=20;
	cout << add(a) << endl;
	cout << add(a,b) << endl;
	return 0;
}
