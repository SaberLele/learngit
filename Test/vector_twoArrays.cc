 ///
 /// @file    vector_twoArrays.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-12-12 23:08:31
 ///

#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

int main()
{
	vector<vector<int> > array(3);

	for(int i=0;i!=3;++i)
	{
		array[i].resize(3);
	}

	for(int i=0;i!=3;++i)
	{
		for(int j=0;j!=3;++j)
		{
			array[i][j] = (i+j);
			cout << array[i][j] << " ";
		}
		cout << endl;
	}
	
	cout << endl;

	array.resize(6);
	array[3].resize(3);
	array[4].resize(3);
	array[5].resize(3);
	for(int i=0;i!=6;++i)
	{
		for(int j=0;j!=3;++j)
		{
			array[i][j] = (i+j);
			cout << array[i][j] << " ";
		}
		cout << endl;
	}

	return 0;

}
