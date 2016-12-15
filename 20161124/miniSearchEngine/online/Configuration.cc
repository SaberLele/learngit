 ///
 /// @file    Configuration.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-27 23:19:53
 ///

#include "Configuration.h"
#include <fstream>
#include <sstream>
using std::ifstream;
using std::istringstream;

namespace zx
{

	ifstream& open_file(ifstream& in,const string & file)
	{
		in.close();
		in.clear();
		in.open(file.c_str());
		return in;
	}

	Configuration::Configuration(const string& filepath)
	:_filepath(filepath)
	,_configMap(getConfigMap())
	,_stopWordList(getStopWordList())
	{
	}

	map<string, string> Configuration::getConfigMap()
	{
		map<string, string> config_map;
		string key, value;

		ifstream map_file;
		if(!open_file(map_file, _filepath))
		{
			std::cout << "no Configuration file" << std::endl;
		}

		while(map_file >> key >> value)
		{
			config_map.insert(make_pair(key,value));
		}
		return config_map;
	}

	set<string> Configuration::getStopWordList()
	{
		set<string> stopWord_set;
		string file_StopWord,value;
		string word = "stopword";

		ifstream stopWord_file;

		map<string,string>::const_iterator map_it = _configMap.find(word);
		if(map_it != _configMap.end())
		{
			file_StopWord = map_it->second;		
		}

		if(!open_file(stopWord_file, file_StopWord))
		{
			std::cout << "no StopWord file" << std::endl;
		}
		while(stopWord_file >> value)
		{
			stopWord_set.insert(value);
		}
		return stopWord_set;
	}
	
}// end of namespace zx
