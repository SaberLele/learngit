 ///
 /// @file    TextQuery.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-01 18:30:59
 ///
 
#include <iostream>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <map>
#include <set>
#include <string>
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::map;
using std::set;
using std::pair;
using std::fstream;

class TextQuery
{
	public:
		void readFile(const string filename);
		void query();
		void display(const string & word);
	private:
		vector<string> _vecLines;
		map<string,set<int> > _mapWord2Line;
		map<string,int> _mapWordFreq;
};

void TextQuery::readFile(const string filename)
{
	string str;
	fstream ifs(filename.c_str());
	if(!ifs.good())
	{
		cout << "ifstream open error" << endl;
		return;
	}
	while(getline(ifs,str))
	{
		_vecLines.push_back(str);
	}
	ifs.close();
}

void TextQuery::query()
{
	string iword;
	for(size_t i=0;i<_vecLines.size();++i)
	{
		std::istringstream iss(_vecLines[i]);
		while(iss>>iword)
		{
			pair<string,int> mapWordFreq(iword,1);
			set<int> row;
//			cout << i << endl;
			row.insert(i+1);
			pair<string,set<int> > mapWord2Line(iword,row);
			pair<map<string,set<int> >::iterator,bool > line=_mapWord2Line.insert(mapWord2Line);
			pair<map<string,int>::iterator,bool> freq= _mapWordFreq.insert(mapWordFreq);
			if(!freq.second)
			{
				(freq.first->second)++;
				(line.first->second).insert(i+1);	
			}
		}
	}
}

void TextQuery::display(const string & word)
{
	cout << word << endl;
	map<string,int>::iterator word_freq;
	word_freq=_mapWordFreq.find(word);
	if(word_freq==_mapWordFreq.end())
	{
		cout<<"no such word"<<endl;
	}
	else
	{
	cout << "\toccurs " << word_freq->second << " times." << endl;

	map<string,set<int> >::iterator word_line;
	word_line = _mapWord2Line.find(word);
	set<int> sl=word_line->second;
	set<int>::iterator it=sl.begin();
	for(;it!=sl.end();++it)
	{
		cout << "\t(line " << *it << ")" << _vecLines[*it-1] << endl;
	}
	}
}

int main()
{
//	string filename,word;
//	cout << "please put in a filename:" << endl;
//	std::cin >> filename;
//	cout << "please put in a word:" << endl;
//	std::cin >> word;

	TextQuery tq;
	string filename="china_daily.txt";
	string word= "the";
	tq.readFile(filename);
	tq.query();
	tq.display(word);

	return 0;
}
