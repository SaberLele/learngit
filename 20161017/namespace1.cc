 ///
 /// @file    namespace1.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-10-17 04:01:42
 ///
 
#include <iostream>
using std::cout;
using std::endl;

namespace A
{
	void dispA()
	{
		cout << "display A" << endl;
	}
}

namespace B
{
	void dispB()
	{
		cout << "display B" << endl;
	}
}

int main()
{
	A::dispA();
	B::dispB();

	return 0;
}
