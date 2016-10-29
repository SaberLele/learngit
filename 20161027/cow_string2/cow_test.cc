 ///
 /// @file    cow_test.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-10-26 02:37:47
 ///

#include "cow.h"
#include <iostream>
using std::cout;
using std::endl;

int main()
{
	String s1 = "hello";
	String s2 = s1;

	cout << "s1 = " << s1 << endl;
	cout << "s1's useCount = " << s1.getRefCnt() << endl;

	String s3 = "world";
	String s4 = s3;
	String s5 = s3;

	cout << "s3's useCount = " << s3.getRefCnt() << endl;
	cout << "s3 = " << s3 << endl;

	cout << endl;
	cout << "发生赋值之后:" << endl;
	s3 = s1;
	cout << "s1 = " << s1 << endl;
	cout << "s3 = " << s3 << endl;
	cout << "s1's useCount = " << s1.getRefCnt() << endl;
	cout << "s4's useCount = " << s4.getRefCnt() << endl;

	cout << endl;
	cout << "发生写操作之后:" << endl;
	s3[0] = 'X';
	cout << "s3 = " << s3 << endl;
	cout << "s1 = " << s1 << endl;
	cout << "s1's useCount = " << s1.getRefCnt() << endl;
	cout << "s3's useCount = " << s3.getRefCnt() << endl;
	printf("s1's address = %p\n", s1.c_str());
	printf("s2's address = %p\n", s2.c_str());
	printf("s3's address = %p\n", s3.c_str());
	
	cout << endl;
	cout << "发生读操作:" << endl;
	cout << s1[0] << endl;
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
	cout << "s1's useCount = " << s1.getRefCnt() << endl;
	cout << "s2's useCount = " << s2.getRefCnt() << endl;
	printf("s1's address = %p\n", s1.c_str());
	printf("s2's address = %p\n", s2.c_str());


	return 0;
}
