 ///
 /// @file    operator_arrow.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-10-25 02:36:55
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Data
{
public:
	int len()
	{
		return 5;
	}
};

class DataPtr
{
	public:
		DataPtr()
		:_pstr(new Data())
		{
		}
		
		~DataPtr()
		{
			delete _pstr;
		}

		Data* operator -> ()
		{
			return _pstr;
		}
	private:
		Data * _pstr;
};

int main()
{
	DataPtr p1;
	cout << p1->len() << endl;
	return 0;
}
