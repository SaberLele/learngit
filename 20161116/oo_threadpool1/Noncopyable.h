 ///
 /// @file    Noncopyable.h
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-16 00:03:44
 ///

#ifndef __NONCOPYABLE_H__
#define __NONCOPYABLE_H__

namespace zx
{
	class Noncopyable
	{
		protected:
			Noncopyable(){}
			~Noncopyable(){}
		private:
			Noncopyable(const Noncopyable&);
			Noncopyable & operator = (const Noncopyable&);
	};
}

#endif
