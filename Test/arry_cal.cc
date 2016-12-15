 ///
 /// @file    arry_cal.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-12-13 00:16:45
 ///
 
#include <iostream>
using std::cout;
using std::endl;

int *cal(int *input, int n)
{
	int i;
	int *result = new int[n];
	result[0] = 1;

	for(i =1; i < n; ++i)   //把每个i的前面乘机统计出来
	{
		result[i] = result[i-1]*input[i-1];
	}

	result[0] = input[n-1];
	for(i = n-2; i>0; --i)    //再乘以i后面的input数据
	{
		result[i] *= result[0];
		result[0] *= input[i];
	}

	for(int i=0; i < n; ++i)
		cout << result[i] << " ";
	cout << endl;

	return 0;
}

int main()
{
	int input[] = {2,3,4,5};
	int length = sizeof(input) / sizeof(int);
	*cal(input,length);

	return 0;
}
