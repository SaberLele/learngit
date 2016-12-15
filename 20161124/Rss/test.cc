 ///
 /// @file    test.cc
 /// @author  chinxi(ccx19930930@gmail.com)
 /// @date    2016-10-27 19:23:32
 ///



#include "rss.h"

#include <sys/types.h>
#include <dirent.h>


#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	DIR * dir;
	dir = opendir("rss");
	if(NULL == dir)
	{
		perror("opendir");
		return -1;
	}

	struct dirent * p_dir;

	while((p_dir = readdir(dir)))
	{
		RssReader rss;
		cout << p_dir->d_name << endl;
		string tmp("rss/");
		tmp += p_dir->d_name;
		rss.parseRss(tmp.c_str());
		rss.dump();
	}
	closedir(dir);
#if 0
	char buf[2556];
	std::ifstream in("pagelib.dat");
	if(!in.is_open())
	{
		cout << "Error opening file" << endl;
		exit(-1);
	}
#endif	
}
