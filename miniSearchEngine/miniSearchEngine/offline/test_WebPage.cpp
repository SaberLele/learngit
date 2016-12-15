 ///
 /// @file    test_WebPage.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-29 23:39:26
 ///

#include "WebPage.h"
#include <boost/regex.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
using std::cout;
using std::endl;

int main()
{
	std::ifstream ifs("Web1.lib");
	std::stringstream buffer;
	buffer << ifs.rdbuf();
	string contents(buffer.str());
//	boost::regex reg("\\s*");
//	string contents = regex_replace(contents1,reg,"");

	zx::Configuration con("/home/saberle/learngit/20161124/miniSearchEngine/offline/my.conf");
	zx::WordSegmentation ws(contents);
	zx::WebPage wp(contents,con,ws);

//	wp.processDoc(contents,con,ws);
//	wp.calcTopK(10);
//	cout << "docId = " << wp.getDocId() << endl;

//	cout << wp.getDoc().size() << endl;

#if 0
	map<string, int> cipin;
	cipin = wp.getWordsMap();
	vector<string> topWords = wp.getTopWord();
	vector<string>::iterator it=topWords.begin();
	for(;it!=topWords.end();++it)
	{
		cout << *it << endl;
	}
	
	map<string,int>::iterator it=cipin.begin();
	for(;it!=cipin.end();++it)
	{
		cout << it->first << "-->" << it->second << endl;
	}
#endif
//	cout << it->first << endl;
//	cout << it->second << endl;
	
}
