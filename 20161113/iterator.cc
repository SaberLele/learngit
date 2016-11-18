 ///
 /// @file    iterator.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-13 05:33:27
 ///
 
#include <iostream>
using std::cout;
using std::endl;

typedef int Data;

class Iterator;

class Aggregate
{
	public:
		virtual Iterator *createIterator()= 0;
		virtual int getsize()=0;
		virtual Data getItem(int nIdx)=0;
		virtual ~Aggregate()
		{
			cout << "~Aggregate()" << endl;
		}
};

class ConcreteAGGregate
:public Aggregate
{
	public:
		ConcreteAGGregate(int size)
		:_size(size)
		,_pData(new Data[_size])
		{
			for(int idx=0;idx!=_size;++idx)
			{
				_pData[idx]=idx;
			}
		}

		Iterator* createIterator();

		int getsize()
		{
			return _size;
		}
		Data getItem(int idx)
		{
			return _pData[idx];
		}
		~ConcreteAGGregate()
		{
			delete []_pData;
		}

	private:
		int _size;
		Data * _pData;
};

class Iterator
{
	public:
		virtual void first()=0;
		virtual void next()=0;
		virtual bool isDone()=0;
		virtual Data currentItem()=0;
		virtual ~Iterator(){};
};

class ConcreteIterator
:public Iterator
{
	public:
		ConcreteIterator(Aggregate *pA)
		:_pA(pA)
		,_idx(0)
		{}
		void first()
		{
			_idx=0;
		}
		void next()
		{
			++_idx;
		}
		bool isDone()
		{
			return _idx==_pA->getsize();
		}
		Data currentItem()
		{
			return _pA->getItem(_idx);
		}
	private:
		Aggregate * _pA;
		int _idx;
};

Iterator* ConcreteAGGregate::createIterator()
{
	return new ConcreteIterator(this);
}

int main()
{	
	Aggregate *pa=new ConcreteAGGregate(10);
	Iterator *it=pa->createIterator();

	for(it->first();!(it->isDone());it->next())
	{
		cout << it->currentItem() << " ";
	}
	cout << endl;

	delete pa;
	delete it;
	return 0;
}
