 ///
 /// @file    protect.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-08 04:21:11
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Base
{
	public:
		void display()
		{
			cout << "Base::_ix=" << _ix << endl;
		}
	protected:
		Base(int ix=0)
		:_ix(ix)
		{
		}
	private:
		int _ix;
};

class Child:public Base
{
	public:
//		Base b;

		Child(int ix)
		:Base(ix)
//		,b()
		{}
};

int main()
{
	Child child(4);
	child.display();

	return 0;
}
