 ///
 /// @file    10_17.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-22 06:14:12
 ///

//A program to transform words.

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
using std::cout;
using std::endl;
using std::map;
using std::string;
using std::ifstream;
using std::istringstream;

ifstream& open_file(ifstream& in, const string & file)
{
	in.close();
	in.clear();
	in.open(file.c_str());
	return in;
}

int main(int argc, char *argv[])
{
	map<string,string> trans_map;
	string key, value;
	if(argc != 3)
	{
		cout << "wrong number argc" << endl;
	}

	ifstream map_file;
	if(!open_file(map_file, argv[1]))
	{
		cout << "no transform file" << endl;
	}

	while(map_file >> key >> value)
	{
		trans_map.insert(make_pair(key,value));
	}

	ifstream input;
	if(!open_file(input, argv[2]))
	{
		cout << "no input file" << endl;
	}

	string line;

	while(getline(input, line))
	{
		istringstream stream(line);

		string word;
		bool firstword = true;
		while(stream >> word)
		{
			map<string,string>::const_iterator map_it=trans_map.find(word);
			if(map_it != trans_map.end())
			{
				word = map_it->second;
			}
			if(firstword)
			{
				firstword=false;
			}
			else
			{
				cout << " ";
			}
			cout << word;
		}
		cout << endl;
	}
	return 0;
}
