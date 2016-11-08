 ///
 /// @file    dynamic_cast.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-08 05:32:53
 ///
 
#include <iostream>
#include <typeinfo>
using std::cout;
using std::endl;

class A
{
	public:
		virtual
		void func()
		{
			cout << "A::func()" << endl;
		}
};

class B : public A
{
	public:
		void func()
		{
			cout << "B::func()"  << endl;
		}
};

int main()
{
	B b;
	A *pa=&b;
	if(B*pb1=dynamic_cast<B*>(pa))
	{
		pb1->func();
	}
	else
	{
		cout << "faile" << endl;
	}
}
