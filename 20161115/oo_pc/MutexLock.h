 ///
 /// @file    MutexLock.h
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-15 04:42:32
 ///

#ifndef __MUTEXLOCK_H__
#define __MUTEXLOCK_H__

#include "Noncopyable.h"
#include <pthread.h>

namespace zx
{
	class MutexLock
	:private Noncopyable
	{
		public:
			MutexLock();
			~MutexLock();

			void lock();
			void unlock();

			pthread_mutex_t* getMutexLockPtr();
	
		private:
			pthread_mutex_t _mutex;
	};

	//锁保护类，防止死锁
	class MutexLockGuard
	{
		public:
			MutexLockGuard(MutexLock & mutex)
			:_mutex(mutex)
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
}//end of namespace zx

#endif
