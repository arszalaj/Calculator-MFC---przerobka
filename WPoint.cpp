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
	double initY) throw()
{
	dX = 350;
	dY = 350;
	int mX = 35;
	int mY = -35;
	x = initX*mX + dX;
	y = initY*mY + dY;
}

WPoint::~WPoint(void)
{
}

double WPoint::GetX(double x)
{
	return x*mX + dX;
}

double WPoint::GetY(double y)
{
	return y*mY + dY;
}