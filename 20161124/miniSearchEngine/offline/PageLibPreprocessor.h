 ///
 /// @file    PageLibPreprocessor.h
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-12-01 00:32:28
 ///

#ifndef __PAGELIBPREPROCESSOR_H__
#define __PAGELIBPREPROCESSOR_H__

#include "Configuration.h"
#include "WebPage.h"
#include "PageLib.h"
#include "WordSegmentation.h"
#include <vector>
#include <string>
#include <map>
using std::vector;
using std::map;
using std::pair;
using std::unordered_map;
using std::string;

namespace zx
{

	class PageLibPreprocessor
	{
		public:
			PageLibPreprocessor(Configuration & conf);
			void doProcess();

		private:
			void readInfoFromFile();
			void cutRedundantPages();
			void buildInvertIndexTable();
			void storeOnDisk();

		private:
			Configuration & _conf;
			vector<WebPage> _pageLib;
			unordered_map<int, pair<int,int> > _offsetLib;
			unordered_map<string, vector<pair<int, double> > > _invertIndexTable;
	};

}//end of namepace zx




#endif
