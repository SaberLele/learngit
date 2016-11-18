 ///
 /// @file    MutexLock.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-15 04:49:32
 ///

#include "MutexLock.h"

namespace zx
{
	MutexLock::MutexLock()
	{
		pthread_mutex_init(&_mutex,NULL);
	}

	MutexLock::~MutexLock()
	{
		pthread_mutex_destroy(&_mutex);
	}

	void MutexLock::lock()
	{
		pthread_mutex_lock(&_mutex);
	}

	void MutexLock::unlock()
	{
		pthread_mutex_unlock(&_mutex);
	}

	pthread_mutex_t* MutexLock::getMutexLockPtr()
	{
		return &_mutex;
	}
}//enf of namespace zx
