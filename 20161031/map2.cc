 ///
 /// @file    map.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-10-31 05:53:20
 ///
 
#include <iostream>
#include <map>
#include <string>
using std::cout;
using std::endl;
using std::map;
using std::string;
using std::pair;
using std::multimap;

int main()
{
	pair<int,string> arrPairs[4]=
	{
		pair<int, string>(9, "Asia"),
		pair<int, string>(4, "America"),
		pair<int, string>(1, "Euro"),
		pair<int, string>(4, "Africa"),
	};
	multimap<int,string,std::greater<int> > mapIntStr(arrPairs,arrPairs+4);
	cout << "mapIntStr's size = " << mapIntStr.size() << endl;

	multimap<int,string>::iterator it;
	for(it = mapIntStr.begin();
		it != mapIntStr.end();++it)
	{
		cout << it->first << " ---> "
			 << it->second << endl;
	}
	cout << endl;

	return 0;
}

