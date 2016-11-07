 ///
 /// @file    virtual2.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-07 05:38:35
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Base
{
	public:
		Base(double ix=0)
		:_ix(ix)
		{}
		virtual
		int func(int x)
		{
			cout << "Base::func(int)" << endl;
			return x;
		}
	private:
		double _ix;
};

class Sub : public Base
{
	public:
		Sub(double ix,double iy)
		:Base(ix)
		,_iy(iy)
		{}

		int func(int x)
		{
			cout << "Sub::func(int)" << endl;
			float y=x;
			return y;
		}

		int func()
		{
			cout << "Sub::fumc()" << endl;
			return 1;
		}
	private:
		double _iy;
};

void test(Base & base)
{
	cout << "x=" << base.func(5) << endl;
}

int main()
{
	cout << "sizeof(Base)=" << sizeof(Base) << endl;
	cout << "sizeof(Sub)=" << sizeof(Sub) << endl;

	Base base(1);
	Sub sub(2,3);
	test(base);
	test(sub);

	Base *b1=&sub;
	b1->func(1);

	sub.func(1);


	return 0;
}
