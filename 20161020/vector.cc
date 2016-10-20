 ///
 /// @file    vector.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-10-20 05:37:46
 ///

#include <vector>
#include <iostream>
using std::cout;
using std::endl;
using std::vector;

void printVector(vector<int> & a)
{
	cout << "a.size=" << a.size() << endl;
	cout << "a.capacity" << a.capacity() << endl;
}

int main()
{
	vector<int> vec;
	printVector(vec);

	vec.push_back(1);
	printVector(vec);

	vec.push_back(2);
	printVector(vec);

	vec.push_back(3);
	printVector(vec);

	vec.push_back(4);
	printVector(vec);

	vec.push_back(5);
	printVector(vec);

	vec.push_back(6);
	printVector(vec);
	
	for(size_t i=0;i!=vec.size();i++)
	{
		cout << "vec=" << vec[i] <<endl;
	}

	vector<int>::iterator it=vec.begin();  //it其实就是一个指针（迭代器）
	for(;it!=vec.end();it++)
	{
		cout << "vec=" << *it << endl;
	}

	for(auto & elem : vec)
	{
		cout << "vec=" << elem <<endl;
	}

	return 0;
}
