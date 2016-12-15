///
/// @file    rss.cc
/// @author  chinxi(ccx19930930@gmail.com)
/// @date    2016-10-27 17:27:49
///

#include "rss.h"
#include "tinyxml2.h"
#include <string.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace tinyxml2;
using namespace std;


string RssReader::boost_regex(string & rhs)
{
	boost::regex re("<.*?>");
	return boost::regex_replace(rhs,re,string(""));
}

void RssReader::parseRss(const char * filename)
{
	_rssData.filename = filename;
	XMLDocument doc;
	doc.LoadFile(filename);
//	cout << filename << endl;


	XMLElement * pNode;
	XMLElement * sub_pNode;
	const char * title;
	const char * link;
	const char * description;
	const char * date;
	const char * content;

	pNode = doc.FirstChildElement("rss");
	if(pNode)
	{
		pNode = pNode->FirstChildElement("channel");
	}else{
		pNode = doc.FirstChildElement("channel");
	}
	if(pNode)
	{
		sub_pNode = pNode->FirstChildElement("title");
		if(sub_pNode)
		{
			title = sub_pNode->GetText();
			if(title)
			{
				_rssData.title = title;
			}
		}
		sub_pNode = sub_pNode->FirstChildElement("link");
		if(sub_pNode)
		{
			link = sub_pNode->GetText();
			if(link)
			{
				_rssData.link = link;
			}
		}
		sub_pNode = pNode->FirstChildElement("description");
		if(sub_pNode)
		{
			description = sub_pNode->GetText();
			if(description)
			{
				_rssData.description = description;
			}
		}
		sub_pNode = pNode->FirstChildElement("pubDate");
		if(sub_pNode)
		{
			date = sub_pNode->GetText();
			if(date)
			{
				_rssData.date = date;
			}
		}else{
			sub_pNode = pNode->FirstChildElement("lastBuildDate");
			if(sub_pNode)
			{
				date = sub_pNode->GetText();
				if(date)
				{
					_rssData.date = date;
				}
			}
		}

		pNode = doc.FirstChildElement("rss")->FirstChildElement("channel")->FirstChildElement("item");
		RssItem rss;

		while(pNode)
		{
			sub_pNode = pNode->FirstChildElement("title");
			if(sub_pNode)
			{
				title = sub_pNode->GetText();
				if(title)
				{
					rss.title = title;
				}
			}
			sub_pNode = pNode->FirstChildElement("link");
			if(sub_pNode)
			{
				link = sub_pNode->GetText();
				if(link)
				{
					rss.link = link;
				}
			}
			sub_pNode = pNode->FirstChildElement("description");
			if(sub_pNode)
			{
				description = sub_pNode->GetText();
				if(description)
				{
					rss.description = description;
					string s;
					s = rss.description;
					rss.description = boost_regex(s);
				}
			}
			sub_pNode = pNode->FirstChildElement("content:encoded");
			if(sub_pNode)
			{
				content = sub_pNode->GetText();
				if(content)
				{
				//	string s;
				//	s = content;
					rss.content = content;
				}
			}
			_rssData.items.push_back(rss);
			pNode = pNode->NextSiblingElement();
		}
	}
}

int RssReader::_num = 0;

void RssReader::increase_num()
{
	++ _num;
}


int RssReader::get_num()
{
	return _num;
}

void RssReader::dump()
{
	ofstream ofs("pagelib.dat",ios::app);

	size_t num = _rssData.items.size();
	size_t i;
	std::string txt;
	ofs.seekp(0,ios::beg);
	for(i=0;i<num;i++)
	{
#if 0
		ofs << "<doc>" << "from:" << _rssData.filename << endl;
		ofs << "\t<docid>" << get_num() << "</docid>" << endl;
		ofs << "\t<title>" << _rssData.items[i].title << "</title>" << endl;	
		ofs << "\t<link>" << _rssData.items[i].link << "</link>" << endl;	
		ofs << "\t<description>" << _rssData.items[i].description << "</description>" << endl;	
		ofs << "\t<content>" << _rssData.items[i].content << "</content>" << endl;	
		ofs << "</doc>" << endl;
#endif
#if 1
		int docid = (increase_num(),get_num());
		cout << docid << endl;
//		cout << "i= " << i << endl;
		txt="<doc> from:" + _rssData.filename +
				   "<docid>" + std::to_string(docid) +
				   "</docid><title>" + _rssData.items[i].title +
				   "</title><link>" + _rssData.items[i].link +
				   "</link><description>" + _rssData.items[i].description +
				   "</description><content>" + _rssData.items[i].content +
				   "</content></doc>";
		ofs << txt;
		cout << ofs.tellp() << endl;
		_rssData.items[docid].offset = ofs.tellp();
#endif
	}
	_rssData.items.clear();
}
