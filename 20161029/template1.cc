 ///
 /// @file    template1.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-10-28 23:26:48
 ///

#include <string>
#include <iostream>
//没有.h的原因是,iostream其内容是由模板编写的,
//而模板不能分成头文件和实现文件的,要一起使用
using std::cout;
using std::endl;
using std::string;

template <typename T>
T add(const T & a,const T & b)
{
	return a+b;
}

int main()
{
	cout << add(10,20) << endl;
	cout << add(1.0,2.0) << endl;
	string s1("hello"),s2("world");
	cout << add(s1,s2) << endl;
	return 0;
}
