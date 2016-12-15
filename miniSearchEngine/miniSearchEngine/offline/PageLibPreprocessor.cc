 ///
 /// @file    PageLibPreprocessor.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-12-01 00:52:01
 ///

#include <stdlib.h>
#include "PageLibPreprocessor.h"
#include <iostream>
#include <cmath>
#include <fstream>
#include <sstream>
using std::ifstream;

namespace zx
{

	PageLibPreprocessor::PageLibPreprocessor(Configuration & conf)
	:_conf(conf)
	{}

	void PageLibPreprocessor::readInfoFromFile()
	{
		map<string,string> conf_map = _conf.getConfigMap();
		string offset_file = conf_map["newoffsetlib"];
		string docId,offset,len;
		ifstream ifs1(offset_file.c_str());
		if(!ifs1.good())
		{
			std::cout << "no offsetLib file" << std::endl;
			exit(-1);
		}
		while(ifs1 >> docId >> offset >> len)
		{
			pair<int,int> tmp;
			tmp = std::make_pair(atoi(offset.c_str()),atoi(len.c_str()));
			_offsetLib.insert(unordered_map<int, pair<int, int> >
							  ::value_type(atoi(docId.c_str()), tmp));
		}
		
		string doc_file = conf_map["newpagelib"];
		ifstream ifs2(doc_file.c_str());
		if(!ifs2.good())
		{
			std::cout << "no pagelib file" << std::endl;
			exit(-1);
		}
		std::stringstream buffer;
		buffer << ifs2.rdbuf();
		string doc(buffer.str());
#if 1
		WordSegmentation jieba;
		unordered_map<int, pair<int, int> >::iterator it = _offsetLib.begin();
		for(;it!=_offsetLib.end();++it)
		{
			string OneDoc = doc.substr(it->second.first,it->second.second);
		//	WordSegmentation jieba(OneDoc);
			jieba.cut(OneDoc);
			WebPage wd(OneDoc, jieba);
			_pageLib.push_back(wd);
		}
#endif
	}

	void PageLibPreprocessor::cutRedundantPages()
	{
		cout << "before: " << _pageLib.size() << endl;
		vector<WebPage>::iterator it = _pageLib.begin();
		for(;it!=_pageLib.end();++it)
		{
			for(vector<WebPage>::iterator jt=it+1; jt!=_pageLib.end();++jt)
			{
				if(*it == *jt)
				{
					swap(*jt, *(_pageLib.end()-1));
					_pageLib.pop_back();
					--jt;
				}
			}
		}
		cout << "after: " << _pageLib.size() << endl;
	}

	void PageLibPreprocessor::buildInvertIndexTable()
	{
//		unordered_map<int,vector<pair<string,int> > > temp_id_words_times;
		unordered_map<string,vector<pair<int,int> > > temp_words_id_times;
		for(auto & elem : _pageLib)
		{
			map<string, int> wordsMap = elem.getWordsMap();
			for(auto & elem2 : wordsMap)
			{
//				temp_id_words_times[elem.getDocId()].push_back(make_pair(elem2.first,elem2.second));
				temp_words_id_times[elem2.first].push_back(make_pair(elem.getDocId(),elem2.second));
			}
		}

		unordered_map<int, vector<pair<string,double> > > temp_id_words_w; 
		double N = _pageLib.size();
		for(auto & elem3 : temp_words_id_times)
		{
			for(auto & elem3_second : elem3.second)
			{
				int id = elem3_second.first;
				double TF = elem3_second.second;
				double DF = elem3.second.size();
				double w = TF*(std::log2(N/(DF+1)));
				temp_id_words_w[id].push_back(make_pair(elem3.first,w));
			}
		}

		for(auto & elem4 : temp_id_words_w)
		{
			double temp_w_total = 0;
			for(auto & elem_w : elem4.second)
			{
				temp_w_total += elem_w.second * elem_w.second; 		
			}
			for(auto & elem_w : elem4.second)
			{
				double temp_w = elem_w.second / (std::sqrt(temp_w_total));
				_invertIndexTable[elem_w.first].push_back(make_pair(elem4.first,temp_w));
			}
		}
	}
	
	void PageLibPreprocessor::storeOnDisk()
	{
		ofstream ofs("lastpage.lib",std::ios::app);
		ofstream ofs1("lastoffset.lib",std::ios::app);
		ofstream ofs2("InvertIndex.lib",std::ios::app);

		for(auto & elem : _pageLib)
		{
			int offset = ofs.tellp();
			int len = elem.getDoc().size();
			ofs << elem.getDoc();
			ofs1 << elem.getDocId() << " " << offset << " " << len << endl;
		}

		for(auto & elem : _invertIndexTable)
		{
			ofs2 << elem.first << " ";
			for(auto & elem2 : elem.second)
			{
				ofs2 << elem2.first << " " << elem2.second << " ";
			}
			ofs2 << endl;
		}

	}

	void PageLibPreprocessor::doProcess()
	{
		readInfoFromFile();
		cutRedundantPages();
		buildInvertIndexTable();
		storeOnDisk();
	}

}//end of namespace zx
