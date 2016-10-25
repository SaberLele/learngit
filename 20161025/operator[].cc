 ///
 /// @file    operator[].cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-10-25 01:39:07
 ///

#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class CharArr
{
	public:
		CharArr(int size)
		:_pbuf(new char[size])
		,_size(size)
		{
		}
		~CharArr()
		{
			delete [] _pbuf;
		}
		int size()
		{
			return _size;
		}
		char & operator [](int index);
	private:
		char * _pbuf;
		int _size;
};

char & CharArr::operator [] (int index)
{
	static char nullchar='\0';
	if(index>=0 && index<size())
	{
		return _pbuf[index];
	}
	else
	{
		cout << "下标越界" << endl;
		return nullchar;
	}
}

int main()
{
	const char* pstr="hello,world";
	int len=strlen(pstr)+1;

	CharArr arr(len);
	for(int index=0;index!=len;++index)
	{
		arr[index]=pstr[index];
	}
	for(int index=0;index!=arr.size();++index)
	{
		cout << arr[index];
	}
	cout << endl;

	return 0;
}
