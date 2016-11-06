 ///
 /// @file    stack.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-01 06:34:02
 ///
 
#include <iostream>
#include <stack>
#include <vector>
#include <string>
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::stack;

int main()
{
	stack<int> v;
	for(int i=0;i<10;++i)
	{
		v.push(i);
		cout << v.top() << " 已入栈" << endl;
	}
	cout << "现在stack的容量: " << v.size() << endl << endl;
	for(int i=0;i<10;++i)
	{
		cout << v.top() << " 准备出栈" << endl;
		v.pop();
	}
	cout << "现在stack的容量: " << v.size() << endl << endl;

	return 0;
}
