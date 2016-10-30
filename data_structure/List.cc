 ///
 /// @file    List.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-10-26 08:05:42
 ///

#include <stdlib.h>
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

class Node{
	public:
		int data;
		Node *pnext;
};

//单向链表类
class LinkList
{
	public:
		LinkList()
		:_head(new Node)
		{
			_head->data=0;
			_head->pnext=NULL;
		}
		~LinkList()
		{
			delete _head;
		}
		void CreateLinkList(int n);
		void InsertNode(int position,int d);
		void TraverseLinkList();
		bool IsEmpty();
		int GetLength();
		void DeleteNode(int position);
		void DeleteLinkList();
	private:
		Node * _head;
};

int LinkList::GetLength()
{
	Node *p=_head->pnext;
	int n=0;
	while(p!=NULL)
	{
		n++;
		p=p->pnext;
	}
	return n;
}

void LinkList::CreateLinkList(int n)
{
	if(n<0)
	{
		cout << "输入结点个数错误!" << endl;
		exit(EXIT_FAILURE);
	}
	else
	{
		Node *pnew,*ptemp;
		ptemp=_head;
		int i=n;
		while(n-- > 0)
		{
			pnew=new Node;
			cout << "输入第" << i-n << "个结点值：";
			cin >> pnew->data;
			pnew->pnext=NULL;
			ptemp->pnext=pnew;
			ptemp=pnew;
		}
	}
}

void LinkList::InsertNode(int position,int d)
{
	if(position<0 || position>GetLength()+1)
	{
		cout << "输入位置有误" << endl;
		exit(EXIT_FAILURE);
	}
	else
	{
		Node *pnew,*ptemp;
		ptemp=_head;
		pnew=new Node;
		pnew->data=d;
		pnew->pnext=NULL;

		while(position-- >1)
			ptemp=ptemp->pnext;

		pnew->pnext=ptemp->pnext;
		ptemp->pnext=pnew;
	}
}

void LinkList::TraverseLinkList()
{
	Node* p=_head->pnext;
	while(p)
	{
		cout << p->data << " ";
		p=p->pnext;
	}
	cout << endl;
}

bool LinkList::IsEmpty()
{
	if(_head->pnext==NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void LinkList::DeleteNode(int position)
{
	if(position<0 || position>GetLength()+1)
	{
		cout << "输入位置有误" << endl;
		exit(EXIT_FAILURE);
	}
	else
	{
		Node * ptemp=_head,*pdelete;
		while(position-- > 1)
			ptemp=ptemp->pnext;
		pdelete=ptemp->pnext;
		ptemp->pnext=pdelete->pnext;
		delete pdelete;
		pdelete=NULL;
	}
}

void LinkList::DeleteLinkList()
{
	Node *pdelete=_head->pnext,*ptemp;
	while(pdelete)
	{
		ptemp=pdelete->pnext;
		_head->pnext=ptemp;
		delete pdelete;
		pdelete=ptemp;
	}
}

int main()
{
	LinkList l;
	int position=0,value = 0,n=0;

	cout << "请输入需要创建单向链表的结点个数：";  
	cin >> n;  
	l.CreateLinkList(n);

	cout << "打印链表值如下：";  
	l.TraverseLinkList();

	cout << "请输入插入结点的位置和值：";  
	cin >> position >> value;  
	l.InsertNode(position, value);

	cout << "打印链表值如下：";  
	l.TraverseLinkList();

	cout << "请输入要删除结点的位置：";  
	cin >> position;  
	l.DeleteNode(position); 

	cout << "打印链表值如下：";  
	l.TraverseLinkList();

	l.DeleteLinkList();
	if(l.IsEmpty())
	{
		 cout << "删除链表成功！" << endl;
	}
	else
	{
		 cout << "删除链表失败！" << endl; 
	}

	return 0;
}
