 ///
 /// @file    pureVirtual.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-08 04:12:25
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class A
{
	public:
		virtual void display()=0;
		virtual void display1()=0;
};

class B : public A
{
	public:
		void display()
		{
			cout << "B::display()" << endl;
		}
		void display1()
		{
			cout << "B::display1()" << endl;
		}
};

class C : public B
{
	public:
		void display()
		{
			cout << "C::display()" << endl;
		}
		void display1()
		{
			cout << "C::display1()" << endl;
		}
};

int main()
{
	A * pa=NULL;
	pa=new C;
	pa->display();
	pa->display1();
}
