 ///
 /// @file    static_cast.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-10-17 06:24:02
 ///
 
#include <iostream>
using std::cout;
using std::endl;

int main()
{
	double a=3.14;
	int b=static_cast<int>(a);
	cout << a << endl;
	cout << b << endl;
}
