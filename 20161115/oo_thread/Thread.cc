 ///
 /// @file    Thread.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-15 03:49:53
 ///

#include "Thread.h"

namespace zx
{
	Thread::Thread()
	:_pthId(0)
	,_isRunning(false)
	{}

	Thread::~Thread()
	{
		if(_isRunning)
		{
			//线程资源在它终止时由系统自动释放
			pthread_detach(_pthId);
		}
	}

	void Thread::start()
	{
		pthread_create(&_pthId,NULL,&Thread::threadFunc,this);
		_isRunning=true;
	}

	void Thread::join()
	{
		if(_isRunning)
		{
			pthread_join(_pthId,NULL);
		}
	}

	void * Thread::threadFunc(void * arg)
	{
		Thread* pthread = static_cast<Thread*>(arg);
		if(pthread)
			pthread->run();
	}
}//end of namespace

