 ///
 /// @file    SafeFile.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-04 05:01:30
 ///
 
#include <iostream>
#include <fstream>
using std::cout;
using std::endl;
using std::ofstream;

class SafeFile
{
	public:
		SafeFile(const char * filename)
		:_pfileHandler(fopen(filename,"w+"))
		{
			cout << "SafeFile(const char *)" << endl;
			if(_pfileHandler==nullptr)
			{
				cout << "open faile" << endl;
			}
		}

		~SafeFile()
		{
			if(_pfileHandler)
			{
				fclose(_pfileHandler);
			}
			cout << "~SafeFile()" << endl;
		}
#if 0
		void write(const char *str)
		{
			if(fputs(str,_pfileHandler)==EOF)
			{
				cout << "write faile" << endl;
			}
		}
#endif
		void write(const char *buff,int size)
		{
			if(fwrite(buff,1,size,_pfileHandler)==0)
			{
				cout << "write error" << endl;
			}
		}

	private:
		SafeFile(const SafeFile&);
		SafeFile & operator=(const SafeFile &);
	private:
	FILE * _pfileHandler;
};

int main()
{
	SafeFile sf("test.txt");
	sf.write("hello,world",5);

	return 0;
}
