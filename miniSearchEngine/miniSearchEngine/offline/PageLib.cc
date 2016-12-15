 ///
 /// @file    PageLib.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-28 04:16:41
 ///

#include "PageLib.h"

namespace zx
{

	PageLib::PageLib(RssReader & rss)
	:_rss(rss)
	{}

	void PageLib::create()
	{
		DIR * dir;
		dir=opendir("RssFile");
		if(NULL==dir)
		{
			perror("opendir");
			exit(-1);
		}

		struct dirent * p_filename;
		while((p_filename=readdir(dir)))
		{
			if(strcmp(p_filename->d_name,".")==0||strcmp(p_filename->d_name,"..")==0)
				continue;
//			cout << p_filename->d_name << endl;
			string s="RssFile/";
			s+=p_filename->d_name;
			cout << s << endl;
			_rss.parseRss(s.c_str());
		}
		_rss.dump();
		closedir(dir);
	}

}//end of namespace zx
