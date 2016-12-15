 ///
 /// @file    test_PageLibPreprocessor.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-12-01 05:48:49
 ///

#include "PageLibPreprocessor.h"
#include <iostream>
using std::cout;
using std::endl;

int main()
{
	zx::RssReader rss;
	zx::PageLib pl(rss);
	pl.create();
	zx::Configuration con("/home/saberle/learngit/20161124/miniSearchEngine/offline/my.conf");

	zx::PageLibPreprocessor pp(con);

	pp.doProcess();
}
