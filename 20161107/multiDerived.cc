 ///
 /// @file    multiDerived.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-07 03:16:43
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class A
{
	public:
		void print()
		{
			cout << "A::print()" << endl;
		}
};
class B
{
	public:
		void print()
		{
			cout << "B::show()" << endl;
		}
};

class C : public A,public B
{
	public:
		void print()
		{
			cout << "C::display()" << endl;
		}
};

int main()
{
	C c;
	c.print();
	c.A::print();

	return 0;
}
