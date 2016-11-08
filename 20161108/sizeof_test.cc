 ///
 /// @file    sizeof_test.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-07 18:09:44
 ///

#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

int main()
{
	int a1[]={1,2,3,4,5,6,7,8};
	int len=sizeof(a1)/sizeof(*a1);
	cout << len << endl;
}
