 ///
 /// @file    Noncopyable.h
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-20 18:10:11
 ///

#ifndef __NONCOPYABLE_H__
#define __NONCOPYABLE_H__

class Noncopyable
{
	protected:
		Noncopyable(){};
		~Noncopyable(){};
	private:
		Noncopyable(const Noncopyable &rhs);
		Noncopyable & operator=(const Noncopyable &rhs);
};

#endif
