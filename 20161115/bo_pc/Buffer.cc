 ///
 /// @file    Buffer.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-15 05:21:27
 ///

#include "Buffer.h"
#include <iostream>
using std::cout;
using std::endl;

namespace zx
{

	Buffer::Buffer(size_t size)
	:_queSize(size)
	,_mutex()
	,_notFull(_mutex)
	,_notEmpty(_mutex)
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
			_notEmpty.wait();
		}
		Data queItem=_que.front();
		_que.pop();
		_notFull.notify();
		return queItem;
	}

}//end of namespace zx
