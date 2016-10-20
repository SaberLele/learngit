 ///
 /// @file    iostream.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-10-20 05:06:33
 ///
 
#include <limits> 
#include <string> 
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;

void Cin_status()
{
	cout << "cin.badbit="  << cin.bad()  << endl;
	cout << "cin.failbit=" << cin.fail() << endl;
	cout << "cin.eofbit="  << cin.eof()  << endl;
	cout << "cin.goodbit=" << cin.good() << endl;
}

int test1()
{
	int num;
	Cin_status();
	while(cin >> num)
	{
		cout << "num=" << num <<endl;
	}
	cout << endl;
	Cin_status();

	cin.clear();
	cout << endl;
	Cin_status();
	
	//清空缓冲区
	cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

	string s;
	cin >> s;
	cout << "s=" << s << endl;

	return 0;
}

void test2()
{
	int num;
	while(cin >> num, !cin.eof())
	{
		if(cin.bad())
		{
			cout << "IO stream corrupted" << endl;
		}
		if(cin.fail())
		{
			cout << "data error,try again" << endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
			continue;
		}
		cout << "num=" << num << endl;
	}
}

int main()
{
	//test1();
	test2();
	return 0;
}
hello world
