 ///
 /// @file    arr_left_small_right_big.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-12-13 04:50:25
 ///
 
#include <iostream>
using std::cout;
using std::endl;

void smallarge(int *arr, int *rightMin, int n)
{
	int i;
	rightMin[n-1] = arr[n-1];
	for(i = n-2; i >= 0 ; --i)
	{
		if(arr[i] < rightMin[i+1])
			rightMin[i] = arr[i];
		else
			rightMin[i] = rightMin[i+1];
	}

	int leftMax = 0x80000000;
	for(i = 0; i < n; ++i)
	{
		if(arr[i] >= leftMax)
		{
			leftMax = arr[i];
			if(leftMax == rightMin[i])
				cout << leftMax << endl;
		}
	}
}

int main()
{
	int arr[] = {7,10,2,6,19,22,32};
	int rightMin[7];
	smallarge(arr,rightMin,7);

	return 0;
}
