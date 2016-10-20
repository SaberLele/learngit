 ///
 /// @file    fstream.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-10-20 06:42:48
 ///

#include <fstream>
#include <iostream>
using std::cout;
using std::endl;
using std::cin;
using std::fstream;


int test1()
{
	fstream fs("test.cc",std::ios::app);
	if(!fs.good())
	{
		cout << "fstream open error" << endl;
		return -1;
	}

	cout << fs.tellg() << endl;
	
	fs.close();
	return 0;
}

int test2()
{
	fstream fs("test2.dat");
	if(!fs.good())
	{
		cout << "fstream open error" << endl;
		return -1;
	}

	int num;
	for(int i=0;i!=10;i++)
	{
		cin >> num;
		fs << num << " ";
	}

	cout << fs.tellg() << endl;

	fs.seekg(0);
	cout << fs.tellg() <<endl;

	for(int i=0;i!=10; i++)
	{
		fs >> num;
		cout << num << " ";
	}
	cout <<endl;

	return 0;
}

int main()
{
	test1();
	return 0;
}
