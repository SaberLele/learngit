 ///
 /// @file    test.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-10-27 06:54:51
 ///


#include "RssReader.h"
#include <iostream>
using std::cout;
using std::endl;

namespace zx
{

RssReader::RssReader()
{
}

RssReader::~RssReader()
{
}

int RssReader::_cout=0;

void RssReader::increase_cout() const
{
	++_cout;
}

int RssReader::get_cout() const
{
	return _cout;	
}

string RssReader::boost_regex(string & rhs)
{
	boost::regex re("<.*?>|&.*?;");
	return boost::regex_replace(rhs,re,string(""));
}

void RssReader::parseRss(const char * filename)
{
	_rssData.filename=filename;
	XMLDocument doc;
	doc.LoadFile(filename);

    XMLElement * root = doc.RootElement();
	XMLElement * channel = root->FirstChildElement("channel");
	if(channel != NULL)
	{
		root = channel;
	}

	XMLElement * title =root->FirstChildElement("title");
	if(title)
	{
		if(title->GetText())
		{
			_rssData.title=title->GetText();
		}
	}

	XMLElement * link =root->FirstChildElement("link");
	if(link)
	{
		if(link->GetText())
		{
			_rssData.link=link->GetText();
		}
	}

	XMLElement * description =root->FirstChildElement("description");
	if(description)
	{
		if(description->GetText())
		{
			_rssData.description=description->GetText();
		}
	}

	XMLElement * date=root->FirstChildElement("pubDate");
	if(date)
	{
		if(date->GetText())
		{
			_rssData.date=date->GetText();
		}
	}else
	{
		date=root->FirstChildElement("lastBuildDate");
		if(date)
		{
			if(date->GetText())
			{
				 _rssData.date=date->GetText();
			}
		}
	}

	XMLElement * item=root->FirstChildElement("item");
	RssItem rssItem;

	while(item)
	{
		XMLElement *title1=item->FirstChildElement("title");
		if(title1)
		{
			if(title1->GetText())
			{
				rssItem.title=title1->GetText();
			}
		}

		XMLElement *link1=item->FirstChildElement("link");
		if(link1)
		{
			if(link1->GetText())
			{
				rssItem.link=link1->GetText();
			}
		}

		XMLElement *description1=item->FirstChildElement("description");
		if(description1)
		{
			if(description1->GetText())
			{
				rssItem.description=description1->GetText();
			
				string s;
				s=rssItem.description;
				rssItem.description=boost_regex(s);
			}
		}

		XMLElement *content1=item->FirstChildElement("content:encoded");
		if(content1)
		{
			if(content1->GetText())
			{
				rssItem.content=content1->GetText();
				string s;
				s=rssItem.content;
				rssItem.content=boost_regex(s);
			}
		}

		_rssData.items.push_back(rssItem);
		item=item->NextSiblingElement();
	}
}


void RssReader::dump()
{
	ofstream ofs("newpage.lib",std::ios::app);
	ofstream ofs1("newoffset.lib",std::ios::app);
	if(!ofs.good() && !ofs1.good())
	{
		cout << "open error" << endl;
		return;
	}
	std::size_t num = _rssData.items.size();
	std::size_t i;
	std::string txt;
	for(i=0; i< num; i++)
	{
		int count = (increase_cout(),get_cout());
#if 0
		cout << "cout= " << count << endl;
		ofs << "\t<doc>" << "from:" << _rssData.filename << endl;
		ofs << "\t<docid>" << count << "</docid>" << endl;
		ofs << "\t<title>" << _rssData.items[i].title << "</title>" << endl; 
		ofs << "\t<link>" << _rssData.items[i].link << "</link>" << endl;
		ofs << "\t<description>" << _rssData.items[i].description << "</description>" << endl;
		ofs << "\t<content>" << _rssData.items[i].content << "</content>" << endl;	
		ofs << "</doc>" << endl;
#endif
		txt="<doc><docid>" + std::to_string(count) +
			"</docid><title>" + _rssData.items[i].title +
			"</title><link>" + _rssData.items[i].link +
			"</link><description>" + _rssData.items[i].description +
			"</description><content>" + _rssData.items[i].content +
			"</content></doc>";
		int offset = ofs.tellp();
		int len = txt.size();

		_offsetLib[count] = std::make_pair(offset, len);
		
		ofs << txt;
		ofs1 << count << " " << offset << " " << len << endl;	
	}
}

map<int, pair<int,int> > RssReader::getOffsetLen()
{
	return _offsetLib;
}

}//end of namespace zx
