 ///
 /// @file    stringstream.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-10-20 19:51:27
 ///

#include <sstream>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using std::cout;
using std::endl;
using std::stringstream;
using std::ostringstream;
using std::istringstream;
using std::string;
using std::ifstream;
using std::vector;

int test1()
{
	int ival=512;
	int ival2=1024;
	stringstream ss;
	ss << "ival= " << ival << " ival2= " << ival2;

	string str=ss.str();    //把缓冲区的内容转换成字符串
	
	cout << str << endl;
#if 0
	while(ss >> str)
	{
		cout << str <<endl;
	}
#endif
#if 1	
	int num;
	while(!ss.eof())
	{
		ss >> str;
		ss >> num;
		cout << str << " "
			<< num << endl;
	}
#endif

	return 0;
}


string int2str(int num)
{
	ostringstream oss;
	oss << num;
	return oss.str();
}

int test()
{
	ifstream ifs("test.cc");
	if(!ifs.good())
	{
		cout << "ifstream open error" <<endl;
		return -1;
	}
	
	vector<string> vecStr;
	string line;
	int cnt=10;
	while(cnt--)
	{
		getline(ifs,line);
		istringstream iss(line);

		string word;
		while(iss >> word)
		{
			vecStr.push_back(word);
		}
	}
	for(auto & elem : vecStr)
	{
		cout << elem <<endl;
	}
	ifs.close();
}

#if 1
int main()
{
	//test1();
	
	int num=100;
	string s=int2str(num);
	cout << "s= " << s << endl;

	test();

	return 0;
}
#endif
