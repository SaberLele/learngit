 ///
 /// @file    const.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-10-17 05:28:29
 ///
 
#include <iostream>
using std::cout;
using std::endl;

int main()
{
	const int a=1;
	cout << "a= " << a << endl;
	const int* pa=&a;      //指针所指向的变量是常量，pointer to const；
	cout << "*pa= " << *pa << endl;
	int const* pb=&a;
	cout << "*pb= " << *pb << endl;

	int b=2;
	cout << "b= " << b << endl;
	int* const pc = &b;
	cout << "*pc= " << *pc << endl;

	int c=3;
	//*pa=c;
	pa=&c;
	cout << "*pa= " << *pa << endl;
	//pc=&c;
	*pc=c;
	cout << "*pc= " << *pc << endl;
}


