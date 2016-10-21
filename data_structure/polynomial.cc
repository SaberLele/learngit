 ///
 /// @file    polynomial.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-10-20 08:50:26
 ///
 
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

typedef struct item{
	double coefficient;    //系数
	int power;    //指数
	struct item *next;
}*POLYNOMIAL,*pItem;

//创建多项式
POLYNOMIAL Create()
{
	pItem head,p;
	double coe;
	int pwr,iterms,i;
	head=p=new item;
	cin >> iterms;    //多项式的项数
	for(i=0;i<iterms;++i)
	{
		cin >> coe >> pwr;
		p->next=new item;
		p->next->coefficient=coe;
		p->next->power=pwr;
		p=p->next;
	}
	p->next=NULL;
	return head;
}

//按照幂次降排序
void Sort(POLYNOMIAL head)
{
	pItem pt,q,p=head;
	while(p->next)
	{
		q=p->next;
		while(q->next)
		{
			if(p->next->power < q->next->power)
			{
				pt=p->next;
				p->next=q->next;
				q->next=p->next->next;
				p->next->next=pt;
			}
			else
				p=p->next;
		}
	}
}

