 ///
 /// @file    test.h
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-10-27 06:45:08
 ///

#include "tinyxml2.h"
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <boost/regex.hpp>
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
	string filename;
	vector<RssItem> items;
}RssData;

class RssReader
{
	public:
		RssReader();
		~RssReader();

		void increase_cout() const;
		int get_cout() const;
		string boost_regex(string &);

		void parseRss(const char * filename);
		void dump();
	private:
		RssData _rssData;
		static int _cout;
};

