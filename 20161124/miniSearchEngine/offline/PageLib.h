 ///
 /// @file    PageLib.h
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-28 00:20:45
 ///

#ifndef __PAGELIB_H__
#define __PAGELIB_H__

#include "Configuration.h"
#include "RssReader.h"
#include <iostream>

namespace zx
{

	class PageLib
	{
		public:
			PageLib(RssReader & rss);
			void create();
		private:
			RssReader & _rss;
	};

}//end of namespace zx

#endif
