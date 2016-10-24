 ///
 /// @file    wordcout.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-10-23 19:44:19
 ///

#include <vector>
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::vector;
using std::string;

struct Record
{
	char* word;
	int count;
};

class WordStatistic
{
	public:
		void read_file(string filename);
		void write_file(string filename);
	private:
		vector<Record> _wordList;
};


