 ///
 /// @file    Noncopyable.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-11-15 10:59:40
 ///
 
#ifndef _WANGDAO_NONCOPYABLE_H__
#define _WANGDAO_NONCOPYABLE_H__


namespace zx
{

class Noncopyable
{
protected:
	Noncopyable(){}
	~Noncopyable(){}
private:
	Noncopyable(const Noncopyable&);
	Noncopyable & operator=(const Noncopyable&);
};

}// end of namespace zx

#endif
