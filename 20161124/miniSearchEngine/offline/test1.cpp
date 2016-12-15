 ///
 /// @file    test1.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-28 22:29:37
 ///

#include "Configuration.h"
#include <iostream>
using std::cout;
using std::endl;

int main()
{
	zx::Configuration con("/home/saberle/learngit/20161124/miniSearchEngine/offline/my.conf");
	map<string,string> configmap;
	configmap = con.getConfigMap();
#if 0
	map<string,string>::iterator map_it = configmap.begin();
	while(map_it!=configmap.end())
	{
		cout << map_it->first << "  " << map_it->second << endl;
		++map_it;
	}
#endif

	int count = 0;
	set<string> stopWords;
	stopWords = con.getStopWordList();
	set<string>::iterator set_it = stopWords.begin();
	while(set_it!=stopWords.end())
	{
		cout << *set_it << endl;
		++count;
		++set_it;
	}

	cout << count << endl;

	return 0;
}
