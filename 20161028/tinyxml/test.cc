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
	boost::regex re("<.*?>");
	return boost::regex_replace(rhs,re,string(""));
}

void RssReader::parseRss(const char * filename)
{
	cout << "parseRss(const char*)" << endl;
	_rssData.filename=filename;
	XMLDocument doc;
	doc.LoadFile(filename);

	XMLElement* root=doc.FirstChildElement("rss");
	if(root)
	{
		root=root->FirstChildElement("channel");
	}
	else
	{
		root=doc.FirstChildElement("channel");
	}

	XMLElement * title =root->FirstChildElement("title");
	if(title)
	{
		_rssData.title=title->GetText();
		cout << "_rssData.title" << endl;
	}

	XMLElement * link =root->FirstChildElement("link");
	if(link)
	{
		_rssData.link=link->GetText();
		cout << "_rssData.link" << endl;
	}

	XMLElement * description =root->FirstChildElement("description");
	if(description)
	{
		const char * des;
		if((des=description->GetText()))
		{
			_rssData.description=des;
		}
		cout << " _rssData.description" << endl;
	}

	XMLElement * date=root->FirstChildElement("pubDate");
	if(date)
	{
		_rssData.date=date->GetText();
	}else
	{
		date=root->FirstChildElement("lastBuildDate");
		if(date)
		{
			 _rssData.date=date->GetText();
		}
	}

	XMLElement * item=root->FirstChildElement("item");
	RssItem rssItem;

	while(item)
	{
		XMLElement *title1=item->FirstChildElement("title");
		if(title1)
		{
			rssItem.title=title1->GetText();
		}

		XMLElement *link1=item->FirstChildElement("link");
		if(link1)
		{
			rssItem.link=link1->GetText();
		}

		XMLElement *description1=item->FirstChildElement("description");
		if(description1)
		{
			rssItem.description=description1->GetText();
			
	//		cout << rssItem.description << endl;
			string s;
			s=rssItem.description;
			rssItem.description=boost_regex(s);
		}

		XMLElement *content1=item->FirstChildElement("content:encoded");
		if(content1)
		{
			rssItem.content=content1->GetText();
			string s;
			s=rssItem.content;
			rssItem.content=boost_regex(s);
		}

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
	increase_cout();
	ofs << "<doc>"         << "from : "            << _rssData.filename  << endl;
	ofs << "<docid>"       << get_cout()           << "</docid>"         << endl;
	ofs << "<title>"       << _rssData.title       << "</title>"         << endl; 
	ofs << "<link>"        << _rssData.link        << "</link>"          << endl;
	ofs << "<description>" << _rssData.description << "</description>"   << endl;
	
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
	_rssData.items.clear();
	ofs.close();
}

int main()
{
//	RssReader rss;
//	rss.parseRss("iteye_news.xml");
//	rss.dump();

	DIR * dir;
	dir=opendir("RssFile");
	if(NULL==dir)
	{
		perror("opendir");
		return -1;
	}
	

	struct dirent * p_filename;
	while((p_filename=readdir(dir)))
	{
		if(strcmp(p_filename->d_name,".")==0||strcmp(p_filename->d_name,"..")==0)
			continue;
		RssReader rss;
		cout << p_filename->d_name << endl;
		string s="RssFile/";
		s+=p_filename->d_name;
		cout << s << endl;
		rss.parseRss(s.c_str());
		rss.dump();
	}
	closedir(dir);
		
	return 0;
}
