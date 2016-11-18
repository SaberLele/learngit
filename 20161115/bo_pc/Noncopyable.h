 ///
 /// @file    Noncopyable.h
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-15 04:34:33
 ///

#ifndef _NONCOPYABLE_H__
#define _NONCOPYABLE_H__

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
}//end of namespace

#endif
