 ///
 /// @file    mem_fn.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-01 07:48:26
 ///
 
#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
using std::cout;
using std::endl;
using std::vector;

class NumVal
{
	public:
		NumVal() :_val(0)
		{}
		NumVal(int val) :_val(val)
		{}
		bool display()
		{
			cout << _val << " ";
			return true;
		}

		bool isEven()
		{
			return (bool)!(_val%2);
		}
		bool isPrime()
		{
			for(int idx=2;idx<=_val/2;++idx)
			{
				if(!(_val%idx))
					return false;
			}
			return true;
		}
	
	private:
		int _val;
};

int main()
{
	vector<NumVal> vec(13);
	for(size_t idx=0;idx!=13;++idx)
	{
		vec[idx]=NumVal(idx+1);
	}
	for_each(vec.begin(),vec.end(),std::mem_fn(&NumVal::display));
	cout << endl;

	vec.erase(remove_if(vec.begin(), vec.end(),std::mem_fn(&NumVal::isPrime)),vec.end());
	for_each(vec.begin(),vec.end(),std::mem_fn(&NumVal::display));
	cout << endl;
}
