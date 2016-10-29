 ///
 /// @file    templateQueue.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-10-28 23:59:01
 ///
 
#include <iostream>
using std::cout;
using std::endl;

template <typename T,int SIZE=10>
class Queue
{
	public:
		Queue()
		:_front(0)
		,_rear(0)
		{
			cout << "Queue()" << endl;
		}
		bool empty() const;
		bool full() const;
		bool push(const T & t);
		bool pop();

		T front() const;
		T back() const;
	private:
		int _front;
		int _rear;
		T _arr[SIZE]; 
};

template <typename T,int SIZE>
bool Queue<T,SIZE>::empty() const
{
	return _front==_rear;
}

template <typename T,int SIZE>
bool Queue<T,SIZE>::full() const
{
	return _front==(_rear+1)% SIZE;
}

template <typename T,int SIZE>
bool Queue<T,SIZE>::push(const T & t)
{
	if(!full())
	{
		_arr[_rear]=t;
		++_rear;
		_rear%=SIZE;
	}else
	{
		cout << "queue is full" << endl;
	}
}

template <typename T,int SIZE>
bool Queue<T,SIZE>::pop()
{
	if(!empty())
	{
		++_front;
		_front%=SIZE;
	}else
	{
		cout << "queue is empty" << endl;
	}
}

template <typename T,int SIZE>
T Queue<T,SIZE>::front() const
{
	if(!empty())
	{
		return _arr[_front];
	}
	else
	{
		cout << "queue is empty" << endl;
		return -1;
	}
}

template <typename T,int SIZE>
T Queue<T,SIZE>::back() const
{
	if(!empty())
	{
		return _arr[(_rear-1+SIZE)%SIZE];
	}
	else
	{
		cout << "queue is empty" << endl;
		return -1;
	}
}


int main()
{
	Queue<int> queue;

	for(int index=1;index!=10;++index)
	{
		queue.push(index);
	}
	cout << "对头元素：" << queue.front() << endl;
	cout << "对头元素出队" << endl;

	queue.pop();

	cout << "对尾元素:" << queue.back() << endl;
	return 0;
}
