 ///
 /// @file    MutexLock.h
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-16 00:20:47
 ///

#ifndef __MUTEX_H__
#define __MUTEX_H__

#include "Noncopyable.h"
#include <pthread.h>

namespace zx
{
	class MutexLock
	:Noncopyable
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
			MutexLock &_mutex;
	};

}//end of namespace zx

#endif
