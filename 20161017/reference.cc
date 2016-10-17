 ///
 /// @file    reference.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-10-17 06:04:25
 ///
 
#include <iostream>
using std::cout;
using std::endl;

void swap(int &a, int &b)
{
	int tmp=a;
	a=b;
	b=tmp;
}

int &fun(int i)
{
	[]

int main()
{
	int a=1;
	int b=10;
	swap(a,b);
	cout << "a= " << a << endl;
	cout << "b= " << b << endl;
}
