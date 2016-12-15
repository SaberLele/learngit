 ///
 /// @file    arr_halfTimes.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-12-13 05:31:11
 ///
 
#include <iostream>
using std::cout;
using std::endl;

int function(int arr[], int n)
{
	int current;
	int num = 0;

	for(int i=0;i<n;++i)
	{
		if(num == 0)
		{
			current = arr[i];
			num = 1;
		}
		else
		{
			if(current == arr[i])
				num++;
			else
				num--;
		}
	}
	return current;
}

int main()
{
	int arr[] = {0,1,2,1,1};
	int axis = function(arr,5);
	cout << axis << endl;
	return 0;
}
