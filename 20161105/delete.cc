 ///
 /// @file    delete.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-06 06:27:22
 ///

#include <stdio.h>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::shared_ptr;
using std::unique_ptr;
using std::string;
using std::vector;

struct Fpclose
{
	void operator()(FILE * fp)
	{
		if(fp)
		{
			fclose(fp);
			cout << "close FILE pointer" << endl;
		}
	}
};

class X
{
	public:
		X()
		{
			cout << "X()" << endl;
		}
		~X()
		{
			cout << "~X()" << endl;
		}
};

int test1()
{
	shared_ptr<FILE> sp(fopen("test.txt","w+"),Fpclose());
	string msg="message";
	fwrite(msg.c_str(),1,msg.size(),sp.get());

	return 0;
}

int test2()
{
	unique_ptr<FILE,Fpclose> up(fopen("test.txt","w+"),Fpclose());
	string msg = "message";
	fwrite(msg.c_str(), 1, msg.size(), up.get());
	return 0;
}

int main()
{
	test2();

	return 0;
}
