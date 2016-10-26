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

void createList(List* phead)
{
	List* p=phead;
	for(int i=1;i!=10;i++)
	{
		List * pNode=new List;
		pNode->data=i;
		pNode->next=NULL;
		p->next=pNode;
		p=pNode;
	}
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
	List *phead;
	phead=new List;
	phead->data=0;
	phead->next=NULL;
	createList(phead);
	show(phead);
	
	List *pre;
	pre=reverse_list(phead);
	show(pre);
	return 0;
}
