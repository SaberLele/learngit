 ///
 /// @file    Thread.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-16 00:12:57
 ///

#include "Thread.h"

namespace zx
{
	Thread::Thread(ThreadCallback cb)
	:_pthId(0)
	,_isRunning(false)
	,_cb(cb)
	{}

	Thread::~Thread()
	{
		if(_isRunning)
		{
			pthread_detach(_pthId);
		}
	}

	void Thread::start()
	{
		pthread_create(&_pthId,NULL,
						&Thread::threadFunc,this);
		_isRunning=true;
	}

	void Thread::join()
	{
		if(_isRunning)
		{
			pthread_join(_pthId,NULL);
		}
	}

	void* Thread::threadFunc(void* arg)
	{
		Thread* pthread=static_cast<Thread*>(arg);
		if(pthread)
			//pthread->run();
			pthread->_cb();
		return NULL;
	}

}//end of namespace zx
