 ///
 /// @file    10_9.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-17 19:21:14
 ///
 
#include <iostream>
#include <map>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::map;
using std::string;

int main()
{
	map<string, int> word_count;
	string word;

	while(cin >> word)
	{
		++word_count[word];
		if(word=="q")
		{
			break;
		}
	}

	cout << "word \t" << "times\t" << endl;

	map<string, int>::iterator it= word_count.begin();
	for(;it!=word_count.end();++it)
	{
		cout << it->first << " \t" << it->second << "\t" << endl;
	}

	return 0;
}

