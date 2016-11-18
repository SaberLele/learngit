 ///
 /// @file    Buffer.h
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-15 05:13:59
 ///

#ifndef __BUFFER_H__
#define __BUFFER_H__

#include "MutexLock.h"
#include "Condition.h"
#include <queue>
using std::queue;

namespace zx
{
	typedef int Data;
	
	class Buffer
	{
		public:
			Buffer(size_t);

			void push(Data);
			Data pop();

			bool full() const;
			bool empty() const;

		private:
			size_t _queSize;
			queue<Data> _que;
			MutexLock _mutex;
			Condition _notFull;
			Condition _notEmpty;
	};
}//end of namespace zx

#endif
