#include "stdafx.h"
#include "WPoint.h"


	int dX = 350;
	int dY = 350;
	int mX = 35;
	int mY = -35;

WPoint::WPoint(void)
{
}

WPoint::WPoint(
	double initX,
	double initY, int width) throw()
{
	x = evaluateCoordinate(initX, 10);
	y = evaluateCoordinate(initY, 10);
}

WPoint::WPoint(
	double initX,
	double initY) throw()
{
	x = evaluateCoordinate(initX, 10);
	y = evaluateCoordinate(initY, 10);
}

WPoint::~WPoint(void)
{
}

double WPoint::GetX(double x, int width)
{
	return evaluateCoordinate(x, width);
}

double WPoint::GetY(double y, int width)
{
	return evaluateCoordinate(y, width);
}

double WPoint::evaluateCoordinate(double coordinate, int width)
{
	return (coordinate*mY/width*10 + dY);
}