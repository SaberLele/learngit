 ///
 /// @file    memory.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-10-18 02:28:18
 ///

#include <stdio.h>
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

int a=0;    //全局变量和静态变量存储在全局/静态区
char* p1;
const int d=100;  //文字常量区

int main()
{
	int b;       //栈区
	char s[]="123456";   //栈区
	char* p2;   
	const char* p3 = "123456";
	static int c=0;     //全局/静态区
	p1=new char[10];
	p2=new char[5];
	strcpy(p1,"123456");
	const int e=10;     //栈区

	printf("&a=%p\n",&a);
	printf("&p1=%p\n",&p1);
	printf("&d=%p\n",&d);
	printf("&e=%p\n",&e);
	printf("&b=%p\n",&b);
	printf("s=%p\n",s);
	printf("&p2=%p\n",&p2);  //栈区
	printf("&p3=%p\n",&p3);   //栈区
	printf("&c=%p\n",&c);

	printf("p1=%p\n",p1);   //new出来的 堆区
	printf("p2=%p\n",p2);   //堆区
	cout << endl;
	
	return 0;
}
