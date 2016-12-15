 ///
 /// @file    MutexLock.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-11-15 14:37:38
 ///
 
#ifndef __WANGDAO_MUTEXLOCK_H__
#define __WANGDAO_MUTEXLOCK_H__

#include "Noncopyable.h"

#include <pthread.h>
#include <stdio.h>

namespace zx
{

class MutexLock : Noncopyable
{
public:
	MutexLock();
	~MutexLock();

	void lock();
	void unlock();

	pthread_mutex_t * getMutexLockPtr();

private:
	pthread_mutex_t _mutex;
};


class MutexLockGuard
{
public:
	MutexLockGuard(MutexLock & mutex)
	: _mutex(mutex)
	{
		_mutex.lock();
	}

	~MutexLockGuard()
	{
		_mutex.unlock();
	}
private:
	MutexLock & _mutex;
};

}// end of namespace zx

#endif
