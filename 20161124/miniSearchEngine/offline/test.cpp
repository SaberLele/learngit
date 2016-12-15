 ///
 /// @file    test.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-28 05:11:36
 ///

#include "PageLib.h"
#include <iostream>
using std::cout;
using std::endl;

int main()
{
	zx::RssReader rss;
	zx::PageLib pl(rss);
	pl.create();	

	return 0;
}
