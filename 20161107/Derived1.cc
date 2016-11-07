 ///
 /// @file    Derived1.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-07 03:45:53
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
		Base(int ix)
		:_ix(ix)
		{
			cout << "Base(int)" << endl;
		}
	private:
		int _ix;
};

class Derived : public Base
{
#if 1
	public:
		Derived()
		:Base()
		{
			cout << "Derived()" << endl;
		}
		Derived(int ix)
		:Base(ix)
		{
			cout << "Derived(int)" << endl;
		}
#endif
};

int main()
{
	Derived d;

	Derived d1(3);

	return 0;
}
