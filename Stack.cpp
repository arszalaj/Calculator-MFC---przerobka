#include "StdAfx.h"
#include "Stack.h"

/**
* Konstruktor bezparametrowy.
* Rezerwuje wst�pnie pami�� na 20 element�w, aby przyspieszy� dzia�anie programu.
*/
CStack::CStack(void)
{
	stack.reserve(20);
}

CStack::~CStack(void)
{
	stack.clear();
}

/**
* Zwraca ilo�� element�w na stosie.
* @return ilo�� element�w (int)
*/
int CStack::getActualSize()
{
	return stack.size();
}
/**
* Sprawdza, czy stos jest pusty.
* @return true, je�eli stos jest pusty, w przeciwnym razie false
*/
bool CStack::isEmpty()
{
	if(!stack.size())
		return true;
	else return false;
}
/**
* K�adzie element na stosie.
* @param element Element klasy string.
*/
void CStack::push(string element)
{
	stack.push_back(element);
}
/**
* Zdejmuje element z g�ry stosu.
* @param obiekt klasy string, do kt�rego zostanie przypisana warto�� elementu ze stosu.
* @return true, je�eli uda�o si� zdj�� element, false - jezeli stos by� pusty.
*/
bool CStack::pop(string &dest)
{
	if(this->isEmpty())
		return false;
	dest = stack[stack.size()-1];
	stack.pop_back();
	return true;
	
}
/**
* Podgl�da element z g�ry stosu, bez �ci�gania go.
* @param obiekt klasy string, do kt�rego zostanie przypisana warto�� elementu ze stosu.
* @return @return true, je�eli by� element na stosie, false - jezeli stos by� pusty.
*/
bool CStack::look(string &bufor)
{
	if(this->isEmpty())
		return false;
	bufor = stack[stack.size()-1];

	return true;
}



