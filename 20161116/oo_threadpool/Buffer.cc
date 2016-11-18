 ///
 /// @file    Buffer.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-16 01:00:44
 ///

#include "Buffer.h"
#include <iostream>

namespace zx
{

	Buffer::Buffer(size_t size)
	:_queSize(size)
	,_mutex()
	,_notFull(_mutex)
	,_notEmpty(_mutex)
	,_flag(false)
	{}

	bool Buffer::full() const
	{
		return _queSize==_que.size();
	}

	bool Buffer::empty() const
	{
		return 0==_que.size();
	}

	void Buffer::push(Data data)
	{
		MutexLockGuard mlg(_mutex);
		while(full())
		{
			_notFull.wait();
		}
		_que.push(data);
		_notEmpty.notify();
	}

	Data Buffer::pop()
	{
		MutexLockGuard mlg(_mutex);
		while(empty())
		{
			if(_flag)
			{
				return nullptr;
			}
			_notEmpty.wait();
		}
		Data queItem = _que.front();
		_que.pop();
		_notFull.notify();

		return queItem;
	}

}//end of namespace zx
