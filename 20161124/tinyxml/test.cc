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
//	cout << "RssReader()" << endl;	
}

RssReader::~RssReader()
{
//	cout << "~RssReader()" << endl;
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
//	cout << "parseRss(const char*)" << endl;
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
//		cout << "_rssData.link" << endl;
	}

	XMLElement * description =root->FirstChildElement("description");
	if(description)
	{
		const char * des;
		if((des=description->GetText()))
		{
			_rssData.description=des;
		}
//		cout << " _rssData.description" << endl;
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
	ofstream ofs("test.data",std::ios::app);
	if(!ofs.good())
	{
		cout << "open error" << endl;
		return;
	}
	size_t num = _rssData.items.size();
	size_t i;
	std::string txt;
	for(i=0; i< num; i++)
	{
		int count = (increase_cout(),get_cout());
		cout << "count= " << count << endl;
		cout << ofs.tellp() << endl;
		_offset.insert(make_pair(count,ofs.tellp()));		
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
		txt="<doc> from:" + _rssData.filename +
			"<docid>" + std::to_string(count) +
			"</docid><title>" + _rssData.items[i].title +
			"</title><link>" + _rssData.items[i].link +
			"</link><description>" + _rssData.items[i].description +
			"</description><content>" + _rssData.items[i].content +
			"</content></doc>";
		ofs << txt;
	}
}

int main()
{
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
