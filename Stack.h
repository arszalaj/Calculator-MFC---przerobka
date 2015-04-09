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
	CStack(void);
	/**
* Destruktor zwalniaj�cy pami�� po pojemniku.
*/
 ~CStack(void);

	int getActualSize();
	void push(string element);
	bool pop(string &dest);
	bool isEmpty();
	bool look(string &bufor);

private:
	//std::vector <std::string> stack; ///< pojemnik element�w klasy string
	std::deque <std::string> stack; ///< pojemnik element�w klasy string
};
