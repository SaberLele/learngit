 ///
 /// @file    ifstream.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-10-20 06:04:12
 ///

#include <vector>
#include <fstream>
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::vector;
using std::ifstream;
using std::string;

int main()
{
	ifstream ifs("test.cc");
	if(!ifs.good())
	{
		cout << "ifstream open error" << endl;
	}
	
	vector<string> vecStr;
	vecStr.reserve(100);

	string s;
	while(getline(ifs,s))
	{
		vecStr.push_back(s);
	}

	for(auto & elem : vecStr)
	{
		cout << elem << endl;
	}

	ifs.close();

	return 0;
}
