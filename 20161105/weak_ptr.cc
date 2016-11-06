 ///
 /// @file    weak_ptr.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-05 00:09:54
 ///
 
#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::shared_ptr;
using std::weak_ptr;

class Parent;
class Child
{
	public:
		Child()
		{
			cout << "child()" << endl;
		}
		~Child()
		{
			cout << "~child()" << endl;
		}
		shared_ptr<Parent> _parentPtr;
};

class Parent
{
	public:
		Parent()
		{
			cout << "Parent()" << endl;
		}
		~Parent()
		{
			cout << "~Parent()" << endl;
		}
		weak_ptr<Child> _childPtr;
};

int main()
{
	shared_ptr<Parent> pParent(new Parent);
	shared_ptr<Child> pChild(new Child);
	cout << "pParent's use_count = " << pParent.use_count() << endl;
	cout << "pChild's use_count = " << pChild.use_count() << endl;
	
	pParent->_childPtr=pChild;
	pChild->_parentPtr=pParent;
	cout << "pParent's use_count = " << pParent.use_count() << endl;
	cout << "pChild's use_count = " << pChild.use_count() << endl;
	
	return 0;
}
