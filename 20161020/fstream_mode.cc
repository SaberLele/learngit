 ///
 /// @file    fstream_mode.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-10-20 06:24:44
 ///

#include <fstream>
#include <iostream>
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;

int test1()
{
	ifstream ifs("test.cc",std::ios::ate);
	if(!ifs.good())
	{
		cout << "ifstream open error" << endl;
		return -1;
	}

	cout << ifs.tellg() << endl;
	
	ifs.close();
	return 0;
}

int test2()
{
	ofstream ofs("test.cc",std::ios::app);
	if(!ofs.good())
	{
		cout << "ofstream open error" << endl;
		return -1;
	}

	cout << ofs.tellp() << endl;

	ofs << "hello world" << endl;

	ofs.close();

	return 0;
}

int main()
{
	//test1();
	test2();

	return 0;
}
