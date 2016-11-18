 ///
 /// @file    function.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-15 01:22:06
 ///
 
#include <iostream>
#include <functional>
using std::cout;
using std::endl;
using std::function;
using std::bind;

int add(int x, int y)
{
	return x + y;
}

struct foo
{
	int add(int x,int y)
	{
		return x + y;
	}
};

int main()
{
	function<int(int,int)> f=add;
	cout << f(1,2) << endl;
	
	function<int(int,int)> f2=bind(&foo::add,foo(),
			std::placeholders::_1,
			std::placeholders::_2);
	cout << f2(3,4) << endl;
	return 0;
}
