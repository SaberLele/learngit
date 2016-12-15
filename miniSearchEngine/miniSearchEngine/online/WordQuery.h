 ///
 /// @file    WordQuery.h
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-12-07 18:56:06
 ///

#ifndef __WORDQUERY_H__
#define __WORDQUERY_H__

#include "WebPage.h"
#include "Configuration.h"
#include "../offline/WordSegmentation.h"

#include <vector>
#include <map>
#include <set>
#include <string>
using std::vector;
using std::map;
using std::set;
using std::string;
using std::unordered_map;

namespace zx
{

	class WordQuery
	{
		public:
			WordQuery(Configuration & conf);
			string doQuery(const string & str);

		private:
			void loadLibrary();
			vector<double> getQueryWordsWeightVector(vector<string> & queryWords);
			bool executeQuery(const vector<string> & queryWords,
							  vector<pair<int,vector<double> > > &resultVec);
			string createJson(vector<int> & docIdVec,
							  const vector<string> & queryWords);
			string returnNoAnswer();

		private:
			Configuration & _conf;
			WordSegmentation _jieba;
			unordered_map<int, WebPage> _pageLib;
			unordered_map<int, pair<int, int> > _offsetLib;
			unordered_map<string, set<pair<int, double> > > _invertIndexTable;
	};

}//end of namespace zx




#endif
