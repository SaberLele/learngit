 ///
 /// @file    Node.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-14 04:09:23
 ///
 
#include "Node.h"
#include <assert.h>

const int HUGE_VAL=0x3ffffff;

double NumberNode::calc() const
{
	return _number;
}

double UminesNode::calc() const
{
	return - _child->calc();
}

double SumNode::calc() const
{
	double result=0.0;
	auto childIt=_childs.begin();
	auto positiveIt=_positives.begin();
	for(;childIt!=_childs.end();
		++childIt,++positiveIt)
	{
		assert(positiveIt!=_positives.end());
		double val=(*childIt)->calc();
		if(*positiveIt)
			result+=val;
		else
			result-=val;
	}
	assert(positiveIt == _positives.end());
	return result;
}

double ProductNode::calc() const
{
	double result=1.0;
	auto childIt=_childs.begin();
	auto positiveIt=_positives.begin();
	for(;childIt!=_childs.end();
		++childIt,++positiveIt)
	{
		assert(positiveIt!=_positives.end());
		double val=(*childIt)->calc();
		if(*positiveIt)
			result*=val;
		else if(val!=0)
			result /= val;
		else
		{
			cout << "Division by zero." << endl;
			return HUGE_VAL;
		}
	}
	assert(positiveIt==_positives.end());
	return result;
}


