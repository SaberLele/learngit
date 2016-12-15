 ///
 /// @file    Buffer.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-11-15 14:55:54
 ///
 
#include "Buffer.h"
#include <iostream>
using std::cout;
using std::endl;


namespace zx
{

Buffer::Buffer(size_t size)
: _queSize(size)
, _mutex()
, _notFull(_mutex)
, _notEmpty(_mutex)
, _flag(true)
{}

bool Buffer::full() const
{
	return _queSize == _que.size();
}

bool Buffer::empty() const
{
	return 0 == _que.size();
}

void Buffer::wakeup()
{
	_flag = false;
	_notEmpty.notifyAll();
}

//push方法运行在生产者线程
void Buffer::push(Data data)
{
	MutexLockGuard mlg(_mutex);
	while(full())  //使用if不能处理条件变量被异常唤醒的情况
	{
		_notFull.wait();
	}
	_que.push(data);
	_notEmpty.notify();
}

//pop方法运行在消费者线程
Data Buffer::pop()
{
	MutexLockGuard mlg(_mutex);
	while(_flag && empty())
	{
		_notEmpty.wait();
	}
	if(_flag){
		Data queItem = _que.front();
		_que.pop();
		_notFull.notify();
		return queItem;
	}else{
		return NULL;
	}
}


}// end of namespace zx
