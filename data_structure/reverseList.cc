 ///
 /// @file    reverseList.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-10-25 07:12:09
 ///
 
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

struct list{
	int data;
	struct list * next;
};
typedef struct list List;

List * reverse_list(List *phead)
{
	if(phead==NULL || phead->next==NULL)
	{
		return phead;
	}
	List* pNode=NULL;
	List* pre=NULL;
	while(phead)
	{
		pNode=phead->next;
		phead->next=pre;
		pre=phead;
		phead=pNode;
	}
	return pre;
}

void addList(List* phead,int a)
{
	if(phead==NULL)
	{
		return ;
	}
	while(phead->next)
	{
		phead=phead->next;
	}
	List* p=new List;
	p->data=a;
	p->next=NULL;
	phead->next=p;
}
void show(List* phead)
{
	while(phead)
	{
		cout << phead->data << ' ';
		phead=phead->next;
	}
	cout << endl;
}

int main()
{
	List *phead=new List;
	phead->next=NULL;
	addList(phead,1);  
	addList(phead,2);  
	addList(phead,3);  
	addList(phead,4);
	show(phead);
	
	reverse_list(phead);
	show(phead);
	return 0;
}
