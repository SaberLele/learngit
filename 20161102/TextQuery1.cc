 ///
 /// @file    TextQuery.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-02 05:14:21
 ///
 
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <set>
using std::cout;
using std::endl;
using std::ifstream;
using std::vector;
using std::map;
using std::string;
using std::set;

class TextQuery
{
	public:
		void readFile(const string filename);
		void query(const string & word);
	private:
		vector<string> _vecLines;
		map<string,set<int> > _mapWord2Line;
		map<string,int> _mapWordFreq;
};

void TextQuery::readFile(const string filename)
{
	ifstream ifs(filename.c_str());
	if(!ifs.good())
	{
		cout << "ifs open fail" << endl;
		return;
	}
	int row=1;
	string line;
	string word;
	while(getline(ifs,line))
	{
		_vecLines.push_back(line);
		std::istringstream iss;
		iss.str(line);
		while(iss >> word)
		{
			_mapWordFreq[word]++;	
			_mapWord2Line[word].insert(row);
		}
		++row;
	}
}

void TextQuery::query(const string & word)
{
	cout << word << "occurs " << _mapWordFreq[word] << "times" << endl;

	for(auto & elems : _mapWord2Line[word])
	{
		cout << "\t(line " << elems << " )" << _vecLines[elems-1] << endl;
	}
	cout << endl;
}

int main()
{
	TextQuery tq;
	tq.readFile("china_daily.txt");
	tq.query("stock");

	return 0;
}
