 ///
 /// @file    Configuration.h
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-27 23:01:20
 ///

#ifndef __CONFIGURATION_H__
#define __CONFIGURATION_H__

#include <iostream>
#include <string>
#include <set>
#include <map>
using std::string;
using std::set;
using std::map;

namespace zx
{

	class Configuration
	{
		public:
			Configuration(const string & filepath);
			map<string, string> getConfigMap();
			set<string>getStopWordList();
		private:
			string _filepath;
			map<string, string> _configMap;
			set<string> _stopWordList;
	};

}//end of namespace zx

#endif
