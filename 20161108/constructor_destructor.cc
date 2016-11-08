 ///
 /// @file    constructor_destructor.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-08 03:58:46
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Base
{
	public:
		Base()
		{
			cout << "Base()" << endl;
		}
		virtual
		void func1()
		{
			cout << "Base::func1()" << endl;
		}
		virtual
		void func2()
		{
			cout << "Base::func2" << endl;
		}
		~Base()
		{
			cout << "~Base()" << endl;
		}
};

class Base1 : public Base
{
	public:
		Base1()
		{
			cout << "Base1()" << endl;
			func1();
		}

		void func1()
		{
			cout << "Base1::func1()" << endl;
		}

		void func2()
		{
			cout << "Base1::func2()" << endl;
		}

		~Base1()
		{
			cout << "~Base1()" << endl;
			func2();
		}
};

class Sub:public Base1
{
	public:
		Sub()
		{
			cout << "Sub()" << endl;
		}
		~Sub()
		{
			cout << "~Sub()" << endl;
		}
		void func1()
		{
			cout << "Sub::func1()" << endl;
		}
		void func2()
		{
			cout << "Sub::func2()" << endl;
		}
};

int main()
{
	Sub sub;
}
