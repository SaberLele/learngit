 ///
 /// @file    namespace2.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-10-17 04:07:37
 ///
 
#include <iostream>
using std::cout;
using std::endl;

namespace A
{
	void displayA()
	{
		cout << "displayA" << endl;
	}
}

namespace B
{
	using A::displayA;
	void displayB()
	{
		displayA();
		cout << "displayB" << endl;
	}
}

int test()
{
	A::displayA();
	B::displayB();

	return 0;
}

int main()
{
	test();

	return 0;
}
