 ///
 /// @file    List.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-10-26 08:05:42
 ///
 
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
		bool isEmpty();
		int GetLength();
		void DeleteNode(int position);
		void DeleteLinkList();
	private:
		Node * _head;
};

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


