 ///
 /// @file    WebPage.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-29 05:23:14
 ///

#include <stdlib.h>
#include "WebPage.h"
#include "WordSegmentation.h"
#include "Configuration.h"
#include <iostream>
#include <algorithm>

namespace zx
{

	typedef std::pair<string, int> PAIR;
	struct CmpByValue
	{
		bool operator()(const PAIR& lhs, const PAIR& rhs)
		{
			return lhs.second > rhs.second;
		}
	};


	WebPage::WebPage(string & doc,
				//	 Configuration & config,
					 WordSegmentation & jieba)
	:_doc(doc)
	{
		processDoc(_doc,jieba);
		calcTopK(_doc,jieba);
	}

	int WebPage::getDocId()
	{
		return _docId;
	}

	string WebPage::getDoc()
	{
		return _doc;
	}

	map<string,int> & WebPage::getWordsMap()
	{
		return _wordsMap;
	}

	vector<string> & WebPage::getTopWord()
	{
		return _topWords;
	}

	void WebPage::processDoc(const string & doc,
							// Configuration & config,
							 WordSegmentation & jieba)
	{
		std::size_t pos1 = doc.find("<docid>");
		std::size_t pos2 = doc.find("</docid>");
	//	_docId = doc[pos1+7]-48;
		string s = doc.substr(pos1+7,pos2-pos1-7);
		_docId = std::atoi(s.c_str());

		pos1 = doc.find("<title>",0);
		pos2 = doc.find("</title>",0);
		_docTitle=doc.substr(pos1+7,pos2-pos1-7);
	//	std::cout << _docTitle << std::endl;

		pos1 = doc.find("<link>",0);
		pos2 = doc.find("</link>",0);
		_docUrl = doc.substr(pos1+6,pos2-pos1-6);
	//	std::cout << _docUrl << std::endl;

		pos1 = doc.find("<description>",0);
		pos2 = doc.find("</description>",0);
		_docContent = doc.substr(pos1+13,pos2-pos1-13);
	//	std::cout<< _docContent << std::endl;

		vector<string> words = jieba.cut(_doc);

//		set<string> stopWords = config.getStopWordList();
#if 0
		set<string>::iterator set_it = stopWords.begin();
		vector<string>::iterator vec_it1 = words.begin();
		while((vec_it1=std::find_first_of(vec_it1,words.end(),
						set_it,stopWords.end())) != words.end())
		{
			words.erase(vec_it1);
		}
#endif
#if 0
		vector<string>::iterator vec_it1 = words.begin();
		for(;vec_it1!=words.end();++vec_it1)
		{
			set<string>::iterator set_it = 
				find(stopWords.begin(),stopWords.end(),*vec_it1);
			if(set_it!=stopWords.end())
				words.erase(vec_it1);
		}
		for(;vec_it!=words.end();++vec_it)
		{
			std::cout << *vec_it << std::endl;
		}
#endif	
		vector<string>::iterator vec_it = words.begin();
		for(;vec_it!=words.end();++vec_it)
		{
			std::pair<map<string, int> :: iterator, bool> ret = 
				_wordsMap.insert(make_pair(*vec_it, 1));
			if(!ret.second)
				++ret.first->second;
		}
	}

	void WebPage::calcTopK(const string & doc, WordSegmentation & jieba)
	{
#if 0
		vector<PAIR> wordsVec(_wordsMap.begin(), _wordsMap.end());
		std::sort(wordsVec.begin(),wordsVec.end(),CmpByValue());
		for(int i=0;i < 20; ++i)
		{
			_topWords.push_back(wordsVec[i].first);
		}
#endif
		_topWords = jieba.topWords(doc);
	}

	bool operator == (const WebPage & lhs,
					  const WebPage & rhs)
	{
#if 0
		vector<string> lhs_topWords = lhs._topWords;
		vector<string> rhs_topWords = rhs._topWords;
		
		std::size_t cnt = 0;
		vector<string>::iterator it = lhs_topWords.begin();
		while((it=std::find_first_of(it, lhs_topWords.end(),
			   rhs_topWords.begin(), rhs_topWords.end()))
				!= lhs_topWords.end())
		{
			++cnt;
			++it;
		}
#endif
		
		int cnt = 0;
		for(auto & elem: lhs._topWords)
		{
			for(auto & elem2 : rhs._topWords)
			{
				if(elem == elem2)
				{
					++cnt;
					break;
				}
			}
		}
		
		if(cnt >= 15)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator < (const WebPage & lhs,
					 const WebPage &rhs)
	{
		int lhs_DocId = lhs._docId;
		int rhs_DocId = rhs._docId;

		if(lhs_DocId < rhs_DocId)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

}//end of namespace zx
