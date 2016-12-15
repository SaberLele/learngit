 ///
 /// @file    Threadpool.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-11-16 11:06:18
 ///

#include "Threadpool.h"
#include "Thread.h"
#include <unistd.h>
#include <iostream>
#include <functional>

using std::cout;
using std::endl;


namespace zx
{

Threadpool::Threadpool(size_t threadNum, size_t bufSize)
: _threadNum(threadNum)
, _bufSize(bufSize)
, _buffer(_bufSize)
, _isExit(false)
{
	_threads.reserve(_threadNum);
}


Threadpool::~Threadpool()
{
	if(!_isExit){
		stop();
	}
}

void Threadpool::start()
{
	for(size_t idx = 0; idx != _threadNum; ++idx)
	{
		shared_ptr<Thread> sp(new Thread(
				std::bind(&Threadpool::threadFunc, this)));
		_threads.push_back(sp);
		sp->start();
	}
}


void Threadpool::stop()
{
	if(!_isExit){
		//先判断任务队列是否还有任务
		while(!_buffer.empty())
		{
			::sleep(1);
		}
		
		_isExit = true;//放在子线程回收之前
		_buffer.wakeup();
		for(auto & elem : _threads){
			elem->join();
		}
	}
}

void Threadpool::addTask(Task task)
{
	_buffer.push(task);
}

Task Threadpool::getTask()
{
	return _buffer.pop();
}

void Threadpool::threadFunc()
{
	while(!_isExit)
	{
		
		cout << "threadId: " << pthread_self() << endl;
		Task task = getTask();
		if(task)
			task();
	}
}


}// end of namespace zx
