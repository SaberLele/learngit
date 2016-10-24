 ///
 /// @file    stack.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-10-23 04:21:04
 ///
 
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class Stack
{
	public:
		Stack();
		void push(int);
		void pop();
		int top();
		bool emty();
		bool full();
	private:
		vector<int> _Stacknum;		
};

Stack::Stack()
{
	cout << "Stack()" << endl;
}

void Stack::push(int num)
{
	if(full())
	{
		cout << "栈已满" << endl;
		return;
	}
	else
	{
		_Stacknum.push_back(num);
	}
}

void Stack::pop()
{
	if(!emty())
	{
		cout << "_Stacknum.size()" << _Stacknum.size() << endl;
		vector<int>::iterator it=_Stacknum.end();
		_Stacknum.erase(it-1);
		cout << "new _Stacknum.size()" << _Stacknum.size() << endl;
			
	}
	else
	{
		cout << "栈内无数据" << endl;
	}
}

int Stack::top()
{
	if(!emty())
	{
		vector<int>::iterator it=_Stacknum.end();
		cout << "栈顶元素为：" << *(it-1) <<endl;
	}
	else
	{
		cout << "栈内无元素" << endl;
	}
	return 0;
}

bool Stack::emty()
{
	return _Stacknum.empty();
}

bool Stack::full()
{
	if(_Stacknum.size()==10)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	Stack s;
	s.push(10);
	s.push(12);
	s.push(14);

//	int num;
	s.top();
//	cout << "栈顶元素：" << endl;

	s.pop();
	s.top();
	//cout << "栈顶元素：" << endl;

	return 0;
}
