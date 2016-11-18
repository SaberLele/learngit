 ///
 /// @file    Condition.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-16 00:40:04
 ///

#include "Condition.h"
#include "MutexLock.h"
#include <iostream>

namespace zx
{

	Condition::Condition(MutexLock & mutex)
	:_mutex(mutex)
	{
		pthread_cond_init(&_cond,NULL);
	}

	Condition::~Condition()
	{
		pthread_cond_destroy(&_cond);
	}

	void Condition::wait()
	{
		pthread_cond_wait(&_cond,_mutex.getMutexLockPtr());
	}

	void Condition::notify()
	{
		pthread_cond_signal(&_cond);
	}

	void Condition::notifyAll()
	{
		pthread_cond_broadcast(&_cond);
	}

}//end of namespace zx
