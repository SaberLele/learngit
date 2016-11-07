 ///
 /// @file    destructor.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-07 04:07:43
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class A
{
	public:
		A(int ix)
		:_ix(ix)
		{
			cout << "A(int)" << endl;
		}
		~A()
		{
			cout << "~A()" << endl;
		}
	private:
		int _ix;
};

class B
{
	public:
		B()
		{
			cout << "B()" << endl;
		}
		~B()
		{
			cout << "~B()" << endl;
		}
};

class C : public A
{
	public:
		C(int ix,int iy)
		:A(ix)
		,_iy(iy)
		,b()
		{
			cout << "C(int,int)" << endl;
		}

		~C()
		{
			cout << "~C()" << endl;
		}

	private:
		int _iy;
		B b;
};

int main()
{
	C c(3,4);

	return 0;
}
