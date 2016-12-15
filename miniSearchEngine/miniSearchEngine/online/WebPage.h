 ///
 /// @file    WebPage.h
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-29 04:54:20
 ///

#ifndef __WEBPAGE_H__
#define __WEBPAGE_H__

#include "Configuration.h"
#include "WordSegmentation.h"
#include <string>
#include <map>
#include <set>
#include <vector>
using std::string;
using std::map;
using std::set;
using std::vector;

namespace zx
{
	class Configuration;
	class WordSegmentation;

	class WebPage
	{
		friend bool operator==(const WebPage & lhs,
							   const WebPage & rhs);
		friend bool operator < (const WebPage & lhs,
								 const WebPage & rhs);
		public:
			WebPage(){}
			WebPage(string & doc,
					WordSegmentation& jieba);
			int getDocId();
			string getTitle();
			string getUrl();
			string summary(const vector<string> & queryWords);
			map<string, int> & getWordsMap();
//			vector<string> & getTopWord();

		private:
			void processDoc(const string & doc,
				//			Configuration & config,
							WordSegmentation& jieba);
			void calcTopK(const string & doc, WordSegmentation & jieba);
		private:
			string _doc;
			int _docId;
			string _docTitle;
			string _docUrl;
			string _docContent;
			string _docSummary;
			vector<string> _topWords;
			map<string, int> _wordsMap;
	};

}//end of namespace zx


#endif
