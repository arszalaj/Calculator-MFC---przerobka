#pragma once
#include <vector>
#include <deque>
#include <string>
using namespace std;

/** 
* Implementacja stosu elementów klasy string z wykorzystaniem pojemnika (vector).
*/
class CStack
{
public:
	/**
	* Konstruktor bezparametrowy.
	*/
	CStack(void);

	/**
	* Destruktor zwalniaj¹cy pamiêæ po pojemniku.
	*/
	~CStack(void);
	
	/**
	* Zwraca iloœæ elementów na stosie.
	* @return iloœæ elementów (int)
	*/
	int getActualSize();

	/**
	* K³adzie element na stosie.
	* @param element Element klasy string.
	*/
	void push(string element);

	/**
	* Zdejmuje element z góry stosu.
	* @param obiekt klasy string, do którego zostanie przypisana wartoœæ elementu ze stosu.
	* @return true, je¿eli uda³o siê zdj¹æ element, false - jezeli stos by³ pusty.
	*/
	bool pop(string &dest);

	/**
	* Sprawdza, czy stos jest pusty.
	* @return true, je¿eli stos jest pusty, w przeciwnym razie false
	*/
	bool isEmpty();

	/**
	* Podgl¹da element z góry stosu, bez œci¹gania go.
	* @param obiekt klasy string, do którego zostanie przypisana wartoœæ elementu ze stosu.
	* @return true, je¿eli by³ element na stosie, false - jezeli stos by³ pusty.
	*/
	bool look(string &bufor);

private:
	//std::vector <std::string> stack; ///< pojemnik elementów klasy string
	std::deque <std::string> stack; ///< pojemnik elementów klasy string
};
