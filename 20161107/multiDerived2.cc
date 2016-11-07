 ///
 /// @file    multiDerived2.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-07 03:27:12
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class A
{
	public:
		A(int ix=0)
		:_ix(ix)
		{
			cout << "A(int)" << endl;
		}
		void setx(int ix)
		{
			_ix=ix;
		}
		void display()
		{
			cout << "A:_ix=" << _ix << endl;
		}
	private:
		int _ix;
};

class B : virtual public A
{};
class C : virtual public A
{};
class D : public B, public C
{};


int main()
{
	D d;
	d.B::display();
	d.C::display();
	d.display();

	cout << "sizeof(A) = " << sizeof(A) << endl;

	cout << "sizeof(B) = " << sizeof(B) << endl;
	cout << "sizeof(C) = " << sizeof(C) << endl;
	cout << "sizeof(D) = " << sizeof(D) << endl;

	return 0;
}
