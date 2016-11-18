 ///
 /// @file    Condition.h
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-15 04:54:18
 ///

#ifndef __CONDITION_H__
#define __CONDITION_H__

#include "Noncopyable.h"
#include <pthread.h>

namespace zx
{
	class MutexLock;
	class Condition
	:private Noncopyable
	{
		public:
			Condition(MutexLock & mutex);
			~Condition();

			void wait();
			void notify();
			void notifyAll();

		private:
			pthread_cond_t _cond;
			MutexLock & _mutex;
	};
}//end of namespace zx


#endif
