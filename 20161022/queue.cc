 ///
 /// @file    queue.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-10-23 05:08:48
 ///

#include <vector>
#include <iostream>
using std::cout;
using std::endl;
using std::vector;

//方法一：
#if 0
class Queue
{
	public:
		Queue();
		void push(int);
		void pop();
		int front();
		int back();
		bool emty();
		bool full();

	private:
		int _head;
		int _tail;
		int _queue[10];
		int _maxsize;
};

Queue::Queue()
:_head(0)
,_tail(0)
,_maxsize(10)
{
	cout << "Queue()" << endl;
}

bool Queue::emty()
{
	return (_tail==_head);
}

bool Queue::full()
{
	return ((_tail+1)% (_maxsize+1) ==_head);
}

void Queue::push(int num)
{
	if(full())
	{
		cout << "队列已满" << endl;
	}
	else
	{
		_queue[_tail]=num;
		cout << _queue[_tail] << endl;
		_tail=(_tail+1)%(_maxsize+1);
	}
}

void Queue::pop()
{
	if(!emty())
	{
		_head=(_head+1)%_maxsize;		
		if(_head==_tail)
		{
			cout << "队列已空" << endl;
		}
	}
	else
	{
		cout << "队列为空" << endl;
	}
}

int Queue::front()
{
	if(!emty())
	{
		return _queue[_head];
	}
	else
	{
		cout << "队列为空" << endl;
		return -1;
	}
}

int Queue::back()
{
	if(!emty())
	{
		return _queue[(_tail-1+_maxsize)%_maxsize];
	}
	else
	{
		cout << "队列为空" << endl;
		return -1;
	}
}

#endif

class Queue
{
	public:
		void push(int);
		void pop();
		void front();
		void back();
		bool emty();
		bool full();
	private:
		vector<int> _queue;
};

bool Queue::emty()
{
	return _queue.empty();
}

bool Queue::full()
{
	if(_queue.size()<10)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void Queue::push(int num)
{
	if(full())
	{
		cout << "队列已满" << endl;
	}
	else
	{
		_queue.push_back(num);
	}
}

void Queue::pop()
{
	vector<int>::iterator it=_queue.begin();
	if(emty())
	{
		cout << "列队空的" << endl;
	}
	else
	{
		cout << "出对列的元素：" << *it << endl;
		_queue.erase(it);
	}
}

void Queue::front()
{
	if(!emty())
	{
		vector<int>::iterator it=_queue.begin();
		cout << "对头为：" << *it << endl;
	}
}

void Queue::back()
{
	if(!emty())
	{
		vector<int>::iterator it=_queue.end();
		cout << "队尾为：" << *(it-1) << endl;
	}
}

int main()
{
	Queue q;
	int i=10;
	while(i)
	{
		q.push(i);
		i--;
	}
	
	q.front();
	q.back();

	q.pop();
	q.pop();
	
	q.front();
	q.back();

	return 0;
}

