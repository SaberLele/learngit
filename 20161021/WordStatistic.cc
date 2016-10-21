 ///
 /// @file    WordStatistic.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-10-20 20:27:18
 ///

#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::string;
using std::stringstream;
using std::istringstream;
using std::map;
using std::setw;
using std::vector;
using std::pair;
typedef pair<string,int> PAIR;

bool comp(const PAIR& a,const PAIR& b)
{
	return a.second < b.second;
}

class WordStatistic
{
	public:
		WordStatistic();
		~WordStatistic();
		void read_file(string filename);
		void write_file(string filename);

	private:
		map<string,int> _m;
};

WordStatistic::WordStatistic()
{
	cout << "WordStatistic()" << endl; 
}

WordStatistic::~WordStatistic()
{
	cout << "~WordStatistic()" <<endl;
}

void WordStatistic::read_file(string filename)
{
	const char *name= filename.c_str();
	ifstream ifs(name);
	if(!ifs.good())
	{
		cout << "ifstram open fail" << endl;
		return;
	}

	string line;
#if 0
	while(!ifs.eof())
	{
		getline(ifs,line);
		istringstream iss(line);
		string word;
		while(iss >> word)
		{
			for(size_t i=0;i<word.size();i++)
			{
				word[i]=tolower(word[i]);
			}
		}
		++_m[word];
	}
#endif
	string word;
	istringstream iss;
	while(getline(ifs,line))
	{
		iss.clear();
		iss.str(line);
		while(iss >> word)
		{
			_m[word]++;
		}
	}

	ifs.close();

#if 0
	for(map<string,int>::iterator i=_m.begin();i!=_m.end();++i)
	{
		cout << setw(10) << i->first << '\t' << i->second << endl;
	}
#endif
}

void WordStatistic::write_file(string filename)
{
	const char* name=filename.c_str();
	ofstream ofs(name);
	if(!ofs.good())
	{
		cout << "ofstream open error" << endl;
		return;	
	}
	
	vector<PAIR> _m_vec(_m.begin(),_m.end());
	sort(_m_vec.begin(),_m_vec.end(),comp);
	
	for(vector<PAIR>::iterator i=_m_vec.begin();i!=_m_vec.end();i++)
	{
		ofs << setw(10) << i->first << '\t' << i->second << endl;
	}
	ofs.close();	
}
		


int main()
{
	//string s="test.txt";
	WordStatistic test;
	test.read_file("The_Holy_Bible.txt");
//	test.read_file("test.txt");
	test.write_file("dictonary.txt");

	return 0;
}


