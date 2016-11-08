 ///
 /// @file    oversee.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-08 03:35:33
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Base
{
	public:
		virtual
		int func(int x)
		{
			cout << "Base::func(int)" << endl;
			return x;
		}
};

class Sub : public Base
{
	public:
		virtual
		int func(float x)
		{
			cout << "Sub::func(float)" << endl;
			float y=x;
			return y;
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

	sub.func(5);
	return 0;
}
