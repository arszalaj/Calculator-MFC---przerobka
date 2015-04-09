#pragma once
#include <vector>
#include <deque>
#include <string>
using namespace std;

/** 
* Implementacja stosu element�w klasy string z wykorzystaniem pojemnika (vector).
*/
class CStack
{
public:
	/**
	* Konstruktor bezparametrowy.
	*/
	CStack(void);

	/**
	* Destruktor zwalniaj�cy pami�� po pojemniku.
	*/
	~CStack(void);
	
	/**
	* Zwraca ilo�� element�w na stosie.
	* @return ilo�� element�w (int)
	*/
	int getActualSize();

	/**
	* K�adzie element na stosie.
	* @param element Element klasy string.
	*/
	void push(string element);

	/**
	* Zdejmuje element z g�ry stosu.
	* @param obiekt klasy string, do kt�rego zostanie przypisana warto�� elementu ze stosu.
	* @return true, je�eli uda�o si� zdj�� element, false - jezeli stos by� pusty.
	*/
	bool pop(string &dest);

	/**
	* Sprawdza, czy stos jest pusty.
	* @return true, je�eli stos jest pusty, w przeciwnym razie false
	*/
	bool isEmpty();

	/**
	* Podgl�da element z g�ry stosu, bez �ci�gania go.
	* @param obiekt klasy string, do kt�rego zostanie przypisana warto�� elementu ze stosu.
	* @return true, je�eli by� element na stosie, false - jezeli stos by� pusty.
	*/
	bool look(string &bufor);

private:
	//std::vector <std::string> stack; ///< pojemnik element�w klasy string
	std::deque <std::string> stack; ///< pojemnik element�w klasy string
};
