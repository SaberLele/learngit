 ///
 /// @file    observer.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-13 06:07:11
 ///

#include <iostream>
#include <list>
#include <algorithm>
using std::cout;
using std::endl;
using std::list;

typedef int State;

class Observer;
class Subject
{
	public:
		Subject()
		:_subjectState(-1)
		{}
		void attach(Observer* ob)
		{
			auto it=std::find(_list.begin(),_list.end(),ob);
			if(it == _list.end())
			{
				cout << "attach Observer" << endl;
				_list.push_back(ob);
			}
		}
		void detach(Observer* ob)
		{
			auto it=std::find(_list.begin(),_list.end(),ob);
			if(it!=_list.end())
			{
				cout << "detach Observer" << endl;
				_list.erase(it);
			}
		}
		void notify();

		virtual void setState(State state)
		{
			_subjectState=state;
		}

		virtual State getState()
		{
			return _subjectState;
		}

		virtual ~Subject(){}

	protected:
		State _subjectState;
		list<Observer*> _list;
};

class ConcreateSubject
:public Subject
{
	public:
		ConcreateSubject()
		:Subject()
		{}
		virtual ~ConcreateSubject(){}
		void setState(State state)
		{
			cout << "SetState By ConcreateSubject" << endl;
			_subjectState=state;
		}
		State getState()
		{
			cout << "GetState By ConcreateSubject" << endl;
			return _subjectState;
		}
};

class Observer
{
	public:
		Observer()
		:_obState(-1)
		{}
		virtual void update(Subject* Subject)=0;
	protected:
		State _obState;
};

void Subject::notify()
{
	cout << "notify()" << endl;
	list<Observer*>::iterator it;
	for(it=_list.begin();it!=_list.end();++it)
	{
		(*it)->update(this);
	}
}

class ConcreateObserver
:public Observer
{
	public:
		ConcreateObserver(){};
		void update(Subject* subject)
		{
			State subState=subject->getState();
			if(_obState!=subState)
			{
				_obState=subState;
				cout << this << ":subState is" << _obState << endl;
			}
		}
};

int main()
{
	Observer* p1=new ConcreateObserver;
	Observer* p2=new ConcreateObserver;

	Subject subject;
	subject.attach(p1);
	subject.attach(p2);
	subject.setState(10);
	subject.notify();

	subject.detach(p1);
	subject.setState(20);
	subject.notify();

	return 0;

}
