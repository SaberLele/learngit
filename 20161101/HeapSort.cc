 ///
 /// @file    HeapSort.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-02 00:15:14
 ///
 
#include <iostream>
using std::cout;
using std::endl;

//(最大)堆的向下调整算法

void maxHeapDown(int *a,int start,int end)
{
	int c=start;     //当前(current)节点的位置
	int l=2*c+1;     //左(left)孩子的位置
	int tmp=a[c];    //当前(current)节点的大小

	for(;l<=end;c=l,l=2*l+1)
	{
		if(l<end && a[l]<a[l+1])
			l++;                      //左右两孩子中选择较大者
		if(tmp>=a[l])
			break;
		else                          //交换值
		{
			a[c]=a[l];
			a[l]=tmp;
		}
	}
}

//堆排序(从小到大)
//a -- 待排序的数组
//n -- 数组的长度

void heapSortAsc(int* a,int n)
{
	int i,tmp;
	// 从(n/2-1) --> 0逐次遍历。遍历之后，得到的数组实际上是一个(最大)二叉堆。
	for(i=n/2-1;i>=0;--i)
	{
		maxHeapDown(a,i,n-1);
	}
	// 从最后一个元素开始对序列进行调整，不断的缩小调整的范围直到第一个元素
	for(i=n-1;i>0;i--)
	{
		tmp=a[0];
		a[0]=a[i];
		a[i]=tmp;
		maxHeapDown(a,0,i-1);
	}
}

int main()
{
	int i;
	int a[]={20,30,90,40,70,110,60,10,100,50,80};
	int ilen=(sizeof(a))/(sizeof(a[0]));

	cout << "before sort:";
	for(i=0;i<ilen;++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	heapSortAsc(a,ilen);

	cout << "after sort:";
	for(i=0;i<ilen;++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	return 0;
}

