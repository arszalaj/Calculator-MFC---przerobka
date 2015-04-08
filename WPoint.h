#pragma once
class WPoint : public CPoint
{
public:
	WPoint(void);
	WPoint(
		_In_ double initX,
		_In_ double initY, int width) throw();
	~WPoint(void);
	double GetX(double x, int width);
	double GetY(double y, int width);
private:
double WPoint::evaluateCoordinate(double coordinate, int width);
};

