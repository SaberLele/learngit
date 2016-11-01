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

int test()
{
	pair<int,string> arrPairs[4]=
	{
		pair<int, string>(9, "Asia"),
		pair<int, string>(4, "America"),
		pair<int, string>(1, "Euro"),
		pair<int, string>(4, "Africa"),
	};
	map<int,string,std::greater<int> > mapIntStr(arrPairs,arrPairs+4);
	cout << "mapIntStr's size = " << mapIntStr.size() << endl;

	map<int,string>::iterator it;
	for(it = mapIntStr.begin();
		it != mapIntStr.end();++it)
	{
		cout << it->first << " ---> "
			 << it->second << endl;
	}
	cout << endl;

	cout << mapIntStr[1] << endl;
	cout << mapIntStr[4] << endl;
	cout << mapIntStr[9] << endl;
	mapIntStr[4] = "America";
	cout << mapIntStr[4] << endl;
	return 0;
}

int main()
{
	pair<string,string> arrPairs[4]=
	{
		pair<string, string>("aa", "Asia"),
		pair<string, string>("bb", "America"),
		pair<string, string>("cc", "Euro"),
		pair<string, string>("dd", "Africa"),
	};
	map<string,string,std::greater<string> > mapIntStr(arrPairs,arrPairs+4);
	cout << "mapIntStr's size = " << mapIntStr.size() << endl;

	map<string,string>::iterator it;
	for(it = mapIntStr.begin();
		it != mapIntStr.end();++it)
	{
		cout << it->first << " ---> "
			 << it->second << endl;
	}
	cout << endl;

	cout << mapIntStr["aa"] << endl;
	cout << mapIntStr["bb"] << endl;
	cout << mapIntStr["cc"] << endl;
	mapIntStr["dd"] = "America";
	cout << mapIntStr["dd"] << endl;
	return 0;
}
