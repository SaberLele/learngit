 ///
 /// @file    Thread.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-11-15 10:27:50
 ///
 
#include "Thread.h"


namespace zx
{

Thread::Thread(ThreadCallback cb)
: _pthId(0)
, _cb(cb)
, _isRunning(false)
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
	pthread_create(&_pthId, NULL, 
					&Thread::threadFunc, this);
	_isRunning = true;
}

void Thread::join()
{
	if(_isRunning){
		pthread_join(_pthId, NULL);
	}
}

void * Thread::threadFunc(void * arg)
{
	Thread * pthread = static_cast<Thread*>(arg);
	if(pthread)
		pthread->_cb();
	return NULL;
}


}//end of namespace zx
