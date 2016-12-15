 ///
 /// @file    Configuration.h
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-12-07 06:06:49
 ///

#ifndef __CONFIGURATION_H__
#define __CONFIGURATION_H__

#include <iostream>
#include <map>
#include <set>
#include <string>
using std::map;
using std::set;
using std::string;

namespace zx
{

	class Configuration
	{
		public:
			Configuration(const string & filepath);
			map<string,string> getConfigMap();
			set<string> getStopWordList();

		private:
			string _filepath;
			map<string, string> _configMap;
			set<string> _stopWordList;
	};

}//end of namespace zx

#endif
