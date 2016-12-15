 ///
 /// @file    Buffer.h
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-16 00:50:05
 ///

#ifndef __BUFFER_H__
#define __BUFFER_H__

#include "MutexLock.h"
#include "Condition.h"
#include "Task.h"

#include <queue>
using std::queue;

namespace zx
{

	typedef Task Data;
	
	class Buffer
	{
		public:
			Buffer(size_t size);

			void push(Data data);
			Data pop();

			bool full() const;
			bool empty() const;

			void notify_ALL()
			{
				_notEmpty.notifyAll();
			}
			void setFlag()
			{
				_flag=true;
			}


		private:
			size_t _queSize;
			queue<Data> _que;
			MutexLock _mutex;
			Condition _notFull;
			Condition _notEmpty;
			bool _flag;
	};

}//end of namespace zx

#endif
