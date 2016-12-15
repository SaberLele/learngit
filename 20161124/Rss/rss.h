///
/// @file    rss.h
/// @author  chinxi(ccx19930930@gmail.com)
/// @date    2016-10-27 17:12:42
///

#include "tinyxml2.h"
#include <iostream>
#include <vector>
#include <string>
#include <sys/types.h>
#include <boost/regex.hpp>


using tinyxml2::XMLDocument;
using std::string;
using std::vector;

struct RssItem
{
	string title;
	string link;
	string description;
	string content;
	int offset;
};
struct RssData
{
	string title;
	string link;
	string description;
	string date;
	string filename;
	vector<RssItem> items;
};   

class RssReader
{
	public:

		void parseRss(const char * filename);//解析
		void dump();//输出

		void increase_num();
		string boost_regex(string &);
		int get_num();
	private:
		RssData _rssData;
		static int _num;
};   


