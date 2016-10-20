 ///
 /// @file    ofstream.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-10-20 06:14:14
 ///

#include <fstream>
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::string;

int main()
{
	ifstream ifs("test.cc");
	if(!ifs.good())
	{
		cout << "ifstream open error" <<endl;
		return -1;
	}

	ofstream ofs("test1.cc");
	if(!ofs.good())
	{
		cout << "ofstream open error" << endl;
		return -1;
	}

	string s;
	while(getline(ifs,s))
	{
		ofs << s << endl;
	}

	ifs.close();
	ofs.close();

	return 0;
}
