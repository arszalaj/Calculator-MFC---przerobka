#include "StdAfx.h"
#include "Stack.h"

CStack::CStack(void)
{
	//stack.reserve(20);
}

CStack::~CStack(void)
{
	stack.clear();
}

int CStack::getActualSize()
{
	return stack.size();
}

bool CStack::isEmpty()
{
	if(!stack.size())
		return true;
	else return false;
}

void CStack::push(string element)
{
	stack.push_back(element);
}

bool CStack::pop(string &dest)
{
	if(this->isEmpty())
		return false;
	dest = stack[stack.size()-1];
	stack.pop_back();
	return true;
	
}

bool CStack::look(string &bufor)
{
	if(this->isEmpty())
		return false;
	bufor = stack[stack.size()-1];

	return true;
}



