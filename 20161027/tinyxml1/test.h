 ///
 /// @file    test.h
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-10-27 06:45:08
 ///

#include "tinyxml2.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::ofstream;

using namespace tinyxml2;

typedef struct RssItem
{
	string title;
	string link;
	string description;
	string content;
}RssItem;

typedef struct RssData
{
	string title;
	string link;
	string description;
	string date;
	vector<RssItem> items;
}RssData;

class RssReader
{
	public:
		RssReader();
		~RssReader();

		void parseRss(const char * rhs);
		void dump();
	private:
		RssData _rssData;
};

