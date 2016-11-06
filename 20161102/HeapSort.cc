 ///
 /// @file    HeapSort.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-02 04:47:44
 ///

#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

//(最小)堆的向下调整算法
void minHeapDown(int *a,int start,int end)
{
	int c=start;
	int l=2*c+1;
	int temp=a[c];

	for(;l<=end;c=l,l=2*l+1)
	{
		if(l<end && a[l]>a[l+1])
			l++;
		if(temp<=a[l])
			break;
		else
		{
			a[c]=a[l];
			a[l]=temp;
		}
	}
}

void heapSortDesc(int*a,int n)
{
	int i,tmp;
	for(i=n/2-1;i>=0;--i)
	{
		minHeapDown(a,i,n-1);
	}

	for(i=n-1;i>0;--i)
	{
		tmp=a[0];
		a[0]=a[i];
		a[i]=tmp;

		minHeapDown(a,0,i-1);
	}
}

int main()
{
	int i;
	int a[]={20,30,90,40,70,110,60,10,100,50,80};
	int len=(sizeof(a))/(sizeof(a[0]));
	cout << "before sort:";
	for (i=0; i<len; i++)
		cout << a[i] << " ";
	cout << endl;

	heapSortDesc(a,len);
	cout << "after  sort:";
	for (i=0; i<len; i++)
		cout << a[i] << " ";
	cout << endl;

	return 0;
}
