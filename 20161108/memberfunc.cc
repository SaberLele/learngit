 ///
 /// @file    memberfunc.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-08 03:50:45
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Base
{
	public:
		virtual
		void display()
		{
			cout << "Base::dispaly()" << endl;
		}
		void func1()
		{
			display();
		}
		void func2()
		{
			Base::display();
		}
};

class Sub:public Base
{
	public:
		void display()
		{
			cout << "Sub::display()" << endl;
		}

		void Subfunc1()
		{
			display();
		}
		void func1()
		{
			display();
		}
		void func2()
		{
			Base::display();
		}
};

int main()
{
	Base base;
	Sub sub;
	base.func1();
	sub.Subfunc1();
	cout << endl;
	
	Base *pbase=&base;
	pbase->func1();
	pbase->func2();
	cout << endl;

	pbase=&sub;
	pbase->func1();
	pbase->func2();
	cout << endl;
}
