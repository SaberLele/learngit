 ///
 /// @file    quickSort.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-10-21 07:53:05
 ///
 
#include <iostream>
using std::cout;
using std::endl;

void quickSort(int* s,int left, int right)
{
	if(left<right)
	{
		int i=left,j=right,x=s[i];
		while(i<j)
		{
			while(i<j&&s[j]>x)
			{
				j--;
			}
			if(i<j)
			{
				s[i]=s[j];
				i++;
			}
			while(i<j && s[i]<x)
				i++;
			if(i<j)
			{
				s[j]=s[i];
				j--;
			}
		}
		s[i]=x;
		quickSort(s,left,i-1);
		quickSort(s,i+1,right);
	}
}

int main()
{
	int a[]={100,98,32,21,43,11,55,88,32,54};
	quickSort(a,0,9);
	for(int i=0;i<10;i++)
	{
		cout<<a[i]<<" ";
	}
	cout << endl;
}
