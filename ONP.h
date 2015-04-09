#pragma once
#include <string>
#include <ctype.h>
#include "Stack.h"
#include <cmath>
#include <iostream>
#include <sstream>

#define _USE_MATH_DEFINES

#define LEFT_ASSOC 0
#define RIGHT_ASSOC 1

#define ERROR -1
#define NUMBER 0
#define FUNCTION 1
#define OPERATOR 2
#define LB 3
#define RB 4
#define EOS 5

using namespace std;

static const string trigonometric[] = {"sin","cos","tan","ctg","NULL"};
static const double pi = 3.14159265;

/** 
* Zawiera pola i metody do przekszta³cania wyra¿enia do postaci ONP oraz do
* oszacowania wyniku wyra¿enia. Korzysta z klasy Stack.
*/
class CONP
{
public:
	/**
	* Konstruktor bezparametrowy.
	*/
	CONP(void);

	/**
	* Destruktor zwalniaj¹cy pamiêæ po pojemniku.
	*/
	~CONP(void);
/**
* Przekszta³ca wyra¿enie w notacji infiksowej do wyra¿enia w notacji ONP.
* @param[in] infix wyra¿enie w notacji infiksowej
* @param[out] onp obiekt klasy string , w którym ma byæ zapisane przekszta³cone do ONP wyra¿enie.
* @return zwraca 0, je¿eli przekszta³cenie sie powiedzie, -1 - jeœli siê nie powiedzie
*/
	int infixToONP(std::string infix,std::string &onp);
/**
* Oblicza wartoœæ wyra¿enia w ONP.
* @param[in] onp wyra¿enie w ONP
* @param[out] result wynik wyra¿enia
* @return zwraca -1, gdy obliczenie nie powiod³o siê, w przeciwnym razie 0.
*/
	int evaluateONP(std::string onp,long double &result);

private:
/**
* Zwraca priotytet operatora oraz jego ³acznoœæ.
* @param[in] op operator
* @param[out] assoc ³¹cznoœæ
* @return priorytet operatora (im wy¿szy, tym wy¿sza kolejnoœæ wykonywania)
*/
	int getPrior(string op,int &assoc);
/**
* Pobiera kolejny element wyra¿enia.
* Elementem mo¿e byæ zarówno liczba, funkcja czy operator.
* @param[in] exp wyra¿enie
* @param[out] buffer bufor
* @param position Pozycja aktualnie przetwarzanego znaku w wyra¿eniu.
* @param[in] ONP 0 - jeœli wyra¿enie w postaci infiksowej, 1 - jeœli wyra¿enie w ONP
* @return typ rozpoznanego elementu (FUNCTION,OPERATOR,NUMBER)
*/
	int getNextElement(string exp,string &buffer, int &position,bool ONP);

};
