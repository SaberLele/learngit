 ///
 /// @file    templateQueue2.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-10-30 04:24:43
 ///

#include <vector>
#include <iostream>
using std::cout;
using std::endl;
using std::vector;

template <typename T,int SIZE=10>
class Queue
{
	public:
		void push(const T &t);
		void pop();
		void front();
		void back();
		bool empty();
		bool full();
	private:
		vector<T> _queue;
};

template <typename T,int SIZE>
bool Queue<T,SIZE>::empty()
{
	return _queue.empty();
}

template <typename T,int SIZE>
bool Queue<T,SIZE>::full()
{
	if(_queue.size()<SIZE)
	{
		return false;
	}
	else
	{
		return true;
	}
}

template <typename T,int SIZE>
void Queue<T,SIZE>::push(const T & t)
{
	if(full())
	{
		cout << "队列已满" << endl;
	}
	else
	{
		_queue.push_back(t);
	}
}

template <typename T,int SIZE>
void Queue<T,SIZE>::pop()
{
	typename vector<T>::iterator it=_queue.begin();
	if(empty())
	{
		cout << "列队空的" << endl;
	}
	else
	{
		cout << "出对列的元素：" << *it << endl;
		_queue.erase(it);
	}
}

template <typename T,int SIZE>
void Queue<T,SIZE>::front()
{
	if(!empty())
	{
		typename vector<T>::iterator it=_queue.begin();
		cout << "对头为：" << *it << endl;
	}
}

template <typename T,int SIZE>
void Queue<T,SIZE>::back()
{
	if(!empty())
	{
		typename vector<T>::iterator it=_queue.end();
		cout << "队尾为：" << *(it-1) << endl;
	}
}

int main()
{
	Queue<int> q;
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


