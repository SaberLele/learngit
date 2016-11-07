 ///
 /// @file    virtual1.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-07 05:16:39
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Base
{
	public:
		virtual int func(int x)
		{
			cout << "Base::func(int)" << endl;
			return x;
		}
};

class Sub : public Base
{
	public:
		virtual int func(int x)
		{
			cout << "Sub::func(int)" << endl;
			float y=x;
			return y;
		}

		virtual int func()
		{
			cout << "Sub::func()" << endl;
			return 1;
		}
};

void test(Base & base)
{
	cout << "x= " << base.func(5) << endl;
}

int main()
{
	Base base;
	Sub sub;

	test(base);
	test(sub);

//	Base & ref =sub;
//	ref.func();
	sub.func();
}
