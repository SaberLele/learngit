 ///
 /// @file    namespace4.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-10-17 05:07:03
 ///
 
#include <iostream>
using std::cout;
using std::endl;

namespace A
{
	void dispalyA()
	{
		cout << "dispalyA" << endl;
	}
}

namespace B
{
	//using A::dispalyA;
	void dispalyB()
	{
		A::dispalyA();
		cout << "displayB" << endl;
	}
}

namespace A
{
	void dispalyAA()
	{
		B::dispalyB();
	}
}

int main()
{
	//A::dispalyA();
	//B::dispalyB();
	A::dispalyAA();

	return 0;
}
