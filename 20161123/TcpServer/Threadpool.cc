 ///
 /// @file    Threadpool.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-16 04:29:04
 ///

#include "Threadpool.h"
#include "Thread.h"
#include "Task.h"
#include <unistd.h>
#include <iostream>
using std::cout;
using std::endl;

namespace zx
{
	
	Threadpool::Threadpool(size_t threadNum, size_t bufSize)
	:_threadNum(threadNum)
	,_bufSize(bufSize)
	,_buffer(_bufSize)
	,_isExit(false)
	{
		_threads.reserve(_threadNum);
	}

	Threadpool::~Threadpool()
	{
		if(!_isExit)
		{
			this->stop();
		}
	}

	void Threadpool::start()
	{
		for(size_t idx=0;idx!=_threadNum;++idx)
		{
			shared_ptr<Thread> sp(new Thread(std::bind(&Threadpool::threadFunc,std::ref(*this))));
			_threads.push_back(sp);
			sp->start();
		}
	}

	void Threadpool::stop()
	{
		if(!_isExit)
		{
			while(!_buffer.empty())
			{
				
			}
			_isExit = true;
			_buffer.setFlag();
			_buffer.notify_ALL();
			for(auto & elem : _threads)
			{
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
			Task task=getTask();
			if(task)
			{
				task();
			}
		}
	}

}//end of namespace zx
