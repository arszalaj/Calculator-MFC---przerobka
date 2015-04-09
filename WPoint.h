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
	* @param[in] initX wspó³rzêdna punktu na osi X
	* @param[in] initY wspó³rzêdna punktu na osi Y
	* @param[in] width zakres wykresu
	*/
	WPoint(
		_In_ double initX,
		_In_ double initY, int width) throw();

	/**
	* Destruktor zwalniaj¹cy pamiêæ.
	*/
	~WPoint(void);

	/**
	* Przelicza wartoœæ wspó³rzêdnej z wykresu na wartoœæ w oknie
	* @param[in] x wspó³rzêdna punktu na osi X
	* @param[in] width zakres wykresu
	* @return wartoœæ wspó³rzêdnej w oknie na osi X
	*/
	double GetX(double x, int width);

	/**
	* Przelicza wartoœæ wspó³rzêdnej z wykresu na wartoœæ w oknie
	* @param[in] y wspó³rzêdna punktu na osi Y
	* @param[in] width zakres wykresu
	* @return wartoœæ wspó³rzêdnej w oknie na osi Y
	*/
	double GetY(double y, int width);
private:
	double WPoint::evaluateCoordinate(double coordinate, int width);
};

