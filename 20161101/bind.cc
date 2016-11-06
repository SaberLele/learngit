 ///
 /// @file    bind.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-01 07:29:23
 ///
 
#include <iostream>
#include <functional>
using std::cout;
using std::endl;
using std::bind;

int func(int x,int y)
{
	cout << "int func(int,int)" << endl;
	return x+y;
}

class A
{
	public:
		int func(int x,int y)
		{
			cout << "A::func(int,int)" << endl;
			return x+y;
		}
};

int test()
{
	using namespace std::placeholders;

	auto f1=bind(func,10,20);
	cout << f1() << endl;

	auto f2=bind(func,10,_1);
	cout << f2(10) << endl;

	auto f3=bind(func,_1,5);
	cout << f3(5) << endl;

	A a;
	auto f4=bind(&A::func,a,_1,100);
	cout << f4(1) << endl;

	auto f5=bind(&A::func,&a,_1,100);
	cout << f5(1) << endl;
	return 0;
}

struct Foo
{
	int data;
};

void f(int n1, int n2, int n3, const int & n4, int n5)
{
	cout << "(" << n1 
		 << "," << n2
		 << "," << n3
		 << "," << n4
		 << "," << n5
		 << ")" << endl;
}

int main()
{
	using namespace std::placeholders;

	int n=7;
	auto f1=bind(f,_3,_4,_2,std::cref(n),_1);
	n=10;
	f1(1,8,1001,100,101,102);

	auto f2=bind(&Foo::data,_1);
	Foo foo;
	foo.data=10;
	cout << f2(foo) << endl;
	return 0;
} 
