 ///
 /// @file    WordQuery.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-12-07 22:42:55
 ///

#include "WordQuery.h"
#include <json/json.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

using std::ifstream;
using std::stringstream;

namespace zx
{

	struct SimilarityCompare
	{
		SimilarityCompare(vector<double> & base)
		:_base(base)
		{}

		bool operator()(const pair<int, vector<double> > & lhs,
						const pair<int, vector<double> > & rhs)
		{
			double lhsCrossProduct = 0;
			double rhsCrossProduct = 0;
			double lhsVectorLength = 0;
			double rhsVectorLength = 0;

			for(std::size_t index = 0; index != _base.size(); ++index)
			{
				lhsCrossProduct += (lhs.second)[index] * _base[index];
				rhsCrossProduct += (rhs.second)[index] * _base[index];
				lhsVectorLength += std::pow((lhs.second)[index], 2);
				rhsVectorLength += std::pow((rhs.second)[index], 2);
			}
			
			if(lhsCrossProduct / std::sqrt(lhsVectorLength) < rhsCrossProduct / sqrt(rhsVectorLength))
			{
				return false;
			}
			else
			{
				return true;
			}
		}

		vector<double> & _base;
	};

	WordQuery::WordQuery(Configuration & conf)
	:_conf(conf)
	{
		loadLibrary();
	}

	string WordQuery::doQuery(const string & str)
	{
		vector<string> queryWords;
		if(str.size() > 0)
		{
			queryWords = _jieba.cut(str);
		}

		for(auto & elem : queryWords)
		{
			std::cout << elem << '\n';
			auto tmp = _invertIndexTable.find(elem);
			if(tmp == _invertIndexTable.end())
			{
				cout << "can not found " << elem << endl;
				return returnNoAnswer();
			}
		}
		std::cout << std::endl;

		vector<double> w_List = getQueryWordsWeightVector(queryWords);
		SimilarityCompare similarityCmp(w_List);

		vector<pair<int, vector<double> > > resultVec;

		if(executeQuery(queryWords,resultVec))
		{
			std::stable_sort(resultVec.begin(), resultVec.end(), similarityCmp);
			vector<int> docIdVec;

			for(auto & elem : resultVec)
			{
				docIdVec.push_back(elem.first);
			}

			return createJson(docIdVec, queryWords);
		}
		else
		{
			return returnNoAnswer();
		}
	}

	void WordQuery::loadLibrary()
	{
		string docId,offset,len;
		string offset_file = "lastoffsetlib";
		string page_file = "lastpagelib";
		ifstream ifs_offset(_conf.getConfigMap()[offset_file].c_str());
		ifstream ifs_page(_conf.getConfigMap()[page_file].c_str());

		if(!(ifs_offset.good() && ifs_page.good()))
		{
			std::cout << "offset and page lib open error" << endl;
		}

		while(ifs_offset >> docId >> offset >> len)
		{
			_offsetLib.insert(make_pair((atoi(docId.c_str())),make_pair(atoi(offset.c_str()),atoi(len.c_str()))));
		}

		std::stringstream buffer;
		buffer << ifs_page.rdbuf();
		string doc(buffer.str());

		unordered_map<int, pair<int, int> >::iterator it = _offsetLib.begin();
		for(;it!=_offsetLib.end();++it)
		{
			string OneDoc = doc.substr(it->second.first,it->second.second);
			_jieba.cut(OneDoc);
			zx::WebPage wp(OneDoc, _jieba);
			_pageLib.insert(make_pair(it->first,wp));
		}

		ifs_page.close();
		ifs_offset.close();

		string InvertIndex_file = "InvertIndexlib";
		ifstream ifs_InvertIndex(_conf.getConfigMap()[InvertIndex_file].c_str());
		if(!ifs_InvertIndex.good())
		{
			std::cout << "InvertIndexlib open error" << endl;
		}
		
		string line, word;
		double weight;
		int id;
		while(getline(ifs_InvertIndex, line))
		{
			stringstream ss(line);
			ss >> word;
			set<pair<int,double> > docId_w;
			while(ss >> id >> weight)
			{
				docId_w.insert(make_pair(id, weight));	
			}
			_invertIndexTable.insert(make_pair(word,docId_w));
		}
		ifs_InvertIndex.close();
	}

	vector<double> WordQuery::getQueryWordsWeightVector(vector<string> & queryWords)
	{
		map<string,int> wordFreqMap;
		for(auto & elem : queryWords)
		{
			++wordFreqMap[elem];
		}

		vector<double> w_List;
		double w_total = 0;
		int N = _offsetLib.size();

		for(auto & elem : queryWords)
		{
			int DF = _invertIndexTable[elem].size();
			double IDF = std::log2(N/(DF + 1));
			int TF = wordFreqMap[elem];
			double w = IDF * TF;
			w_List.push_back(w);
			w_total += std::pow(w,2);
		}
		
		for(auto & elem : w_List)
		{
			elem /= std::sqrt(w_total);
		}

		return w_List;	
	}

	bool WordQuery::executeQuery(const vector<string> & queryWords,
								 vector<pair<int,vector<double> > > &resultVec)
	{
		if(queryWords.size() == 0)
		{
			std::cout << "empty find words" << endl;
			return false;
		}

		typedef set<pair<int, double> >::iterator setIter;
		vector<pair<setIter, int> > iterVec;
		int minIterNum = 0x7FFFFFFF;
		for(auto & elem : queryWords)
		{
			int num = _invertIndexTable[elem].size();
			if(num == 0)
			{
				return false;
			}
			if(minIterNum > num)
			{
				minIterNum = num;
			}

			iterVec.push_back(make_pair(_invertIndexTable[elem].begin(),0));
		}

		bool isExiting = false;
		while(!isExiting)
		{
			std::size_t idx = 0;
			for(;idx != iterVec.size()-1;++idx)
			{
				if((iterVec[idx].first)->first != (iterVec[idx+1].first)->first)
				{
					break;
				}
			}

			if(idx == iterVec.size() - 1)
			{
				vector<double> weightVec;
				int docId = iterVec[0].first->first;
				for(idx = 0; idx != iterVec.size(); ++idx)
				{
					weightVec.push_back(iterVec[idx].first->second);
					++(iterVec[idx].first);
					++(iterVec[idx].second);
					if(iterVec[idx].second == minIterNum)
					{	isExiting = true;	}
				}
				resultVec.push_back(make_pair(docId,weightVec));
			}
			else
			{
				int minDocId = 0x7FFFFFFF;
				int iterIdx;
				for(idx = 0; idx != iterVec.size(); ++idx)
				{
					if(iterVec[idx].first->first < minDocId)
					{
						minDocId = iterVec[idx].first->first;
						iterIdx = idx;
					}
				}

				++(iterVec[iterIdx].first);
				++(iterVec[iterIdx].second);
				if(iterVec[iterIdx].second == minIterNum)
				{
					isExiting = true;
				}
			}
		}
		return true;
	}

	string WordQuery::createJson(vector<int> & docIdVec,
								 const vector<string> & queryWords)
	{
		Json::Value root;
		Json::Value arr;

		int cnt = 0;
		for(auto & id : docIdVec)
		{
			string summary = _pageLib[id].summary(queryWords);
			string title = _pageLib[id].getTitle();
			string url = _pageLib[id].getUrl();
			
			Json::Value elem;
			elem["title"] = title;
			elem["summary"] = summary;
			elem["url"] = url;
			arr.append(elem);
			if(++cnt == 100)
			{
				break;
			}
		}

		root["files"] = arr;
		Json::StyledWriter writer;
		return writer.write(root);
	}

	string WordQuery::returnNoAnswer()
	{
		Json::Value root;
		Json::Value arr;

		Json::Value elem;
		elem["title"] = "404, no found";
		elem["summary"] = "I cannot find what you want. What a pity!";
		elem["url"] = "";
		arr.append(elem);
		root["files"] = arr;
		Json::StyledWriter writer;
		return writer.write(root);
	}

}//end of namespaze zx
