#pragma once
class WPoint : public CPoint
{
public:
	/**
	* Konstruktor bezparametrowy.
	*/
	WPoint(void);

	/**
	* Konstruktor parametrowy.
	* @param[in] initX wsp�rz�dna punktu na osi X
	* @param[in] initY wsp�rz�dna punktu na osi Y
	* @param[in] width zakres wykresu
	*/
	WPoint(
		_In_ double initX,
		_In_ double initY, int width) throw();

	/**
	* Destruktor zwalniaj�cy pami��.
	*/
	~WPoint(void);

	/**
	* Przelicza warto�� wsp�rz�dnej z wykresu na warto�� w oknie
	* @param[in] x wsp�rz�dna punktu na osi X
	* @param[in] width zakres wykresu
	* @return warto�� wsp�rz�dnej w oknie na osi X
	*/
	double GetX(double x, int width);

	/**
	* Przelicza warto�� wsp�rz�dnej z wykresu na warto�� w oknie
	* @param[in] y wsp�rz�dna punktu na osi Y
	* @param[in] width zakres wykresu
	* @return warto�� wsp�rz�dnej w oknie na osi Y
	*/
	double GetY(double y, int width);
private:
	double WPoint::evaluateCoordinate(double coordinate, int width);
};

