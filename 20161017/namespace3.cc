 ///
 /// @file    namespace3.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-10-17 04:47:46
 ///

#include <iostream>
using std::cout;
using std::endl;

int num=1;

namespace A
{
	int num=10;
}

namespace B
{
	int num=100;
	void display()
	{
		int num=1000;
		cout << "全局num = " << ::num << endl;
		cout << "A::num = " << A::num << endl;
		cout << "B::num = " << B::num << endl;
		cout << "display::num = " << num << endl;
	}
}

int main()
{
	B::display();

	return 0;
}
