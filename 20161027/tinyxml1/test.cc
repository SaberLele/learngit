 ///
 /// @file    test.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-10-27 06:54:51
 ///

#include "test.h"
#include <iostream>
using std::cout;
using std::endl;

RssReader::RssReader()
{
	cout << "RssReader()" << endl;	
}

RssReader::~RssReader()
{
	cout << "~RssReader()" << endl;
}

void RssReader::parseRss(const char * rhs)
{
	cout << "parseRss(const char*)" << endl;
	XMLDocument doc;
	doc.LoadFile(rhs);
	cout << "parseRss(const char*)" << endl;

	XMLElement* root=doc.FirstChildElement("rss")->FirstChildElement("channel");

	XMLElement * title =root->FirstChildElement("title");
	_rssData.title=title->GetText();
	cout << _rssData.title << endl;

	XMLElement * link =root->FirstChildElement("link");
	_rssData.link=link->GetText();
	cout << _rssData.link << endl;

	XMLElement * description =root->FirstChildElement("description");
	_rssData.description=description->GetText();
	cout << _rssData.description << endl;

	XMLElement * date=root->FirstChildElement("pubDate");
	_rssData.date=date->GetText();
	cout << _rssData.date << endl;

	XMLElement * item=root->FirstChildElement("item");
	
	while(item)
	{
		RssItem rssItem;
		XMLElement *title1=item->FirstChildElement("title");
		rssItem.title=title1->GetText();
		cout << rssItem.title << endl;

		XMLElement *link1=item->FirstChildElement("link");
		rssItem.link=link1->GetText();
		cout << rssItem.link << endl;

		XMLElement *description1=item->FirstChildElement("description");
		rssItem.description=description1->GetText();

		XMLElement *content1=item->FirstChildElement("content:encoded");
		rssItem.content=content1->GetText();

		_rssData.items.push_back(rssItem);
		item=item->NextSiblingElement();
	}
}

void RssReader::dump()
{
	cout << "dump()" << endl;
	ofstream ofs("test.data");
	if(!ofs.good())
	{
		cout << "open error" << endl;
		return;
	}
	ofs << "<title>"       << _rssData.title << "</title>"             << endl; 
	ofs << "<link>"        << _rssData.link  << "</link>"              << endl;
	ofs << "<description>" << _rssData.description << "</description>" << endl;
	
	vector<RssItem>::iterator it=_rssData.items.begin();
	for(;it!=_rssData.items.end();++it)
	{
		ofs << "<item>"        << endl;
		ofs << "<title>"       << (*it).title       << "</title>"       << endl;
		ofs << "<link>"        << (*it).link        << "</link>"        << endl;
		ofs << "<description>" << (*it).description << "</description>" << endl;
		ofs << "<content>"     << (*it).content     << "</content>"     << endl;
		ofs << "</item>"       << endl;
	}
	ofs.close();
}

int main()
{
	RssReader rss;
	rss.parseRss("douban.book.review.xml");
	rss.dump();

	return 0;
}
