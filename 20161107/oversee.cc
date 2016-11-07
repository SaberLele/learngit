 ///
 /// @file    oversee.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-07 04:23:10
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class A
{
	public:
		void display()
		{
			cout << "A::display(),A::_ix=" << _ix << endl;
		}
		void display(int ix)
		{
			_ix=ix;
			cout << "A::display(int),ix=" << ix << endl;
		}
	protected:
		int _ix;
};

class B : public A
{
#if 1
	public:
		void display()
		{
			_ix=100;
			A::_ix=22;
			cout << "B::display(),B::_ix=" << _ix << endl;
		}
		int _ix;
#endif
};

int main()
{
	B b;
	b.display();

	b.A::display(3);
	b.A::display();

	return 0;
}
