 ///
 /// @file    templateStack.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-10-28 23:39:01
 ///
 
#include <iostream>
using std::cout;
using std::endl;

template <typename T,int SIZE=10>

class Stack
{
	public:
		Stack()
		:_top(0)
		{
		}
		bool empty() const;
		bool full() const;
		bool push(const T & t);
		bool pop(T & t);
		T top() const;

	private:
		int _top;
		T _arr[SIZE];
};

template <typename T, int SIZE>
bool Stack<T,SIZE>::empty() const
{
	return _top==0;
}

template <typename T, int SIZE>
bool Stack<T,SIZE>::full() const
{
	return _top==SIZE;
}

template <typename T, int SIZE>
bool Stack<T,SIZE>::push(const T & t)
{
	if(!full())
	{
		_arr[_top++]=t;
		return true;
	}
	else
	{
		return false;
	}
}

template <typename T, int SIZE>
bool Stack<T,SIZE>::pop(T & t)
{
	if(!empty())
	{
		--_top;
		t=_arr[_top];
		return true;
	}
	else
	{
		return false;
	}
}

template <typename T, int SIZE>
T Stack<T,SIZE>::top() const
{
	return _arr[_top-1];
}

int main()
{
	Stack<int> stack;
	cout << "开始时stack是否为空?" << stack.empty() << endl;
	stack.push(5);
	cout << "此时stack是否为空?" << stack.empty() << endl;

	for(int idx = 1; idx != 10; ++idx)
	{
		stack.push(idx);
	}
	cout << "此是stack是否已满?" << stack.full() << endl;
	
	int value;
	while(stack.pop(value))
	{
		cout << value << " ";
	}
	cout << endl;
	cout << "此时stack是否为空?" << stack.empty() << endl;

	return 0;
}
