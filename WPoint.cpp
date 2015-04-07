#include "stdafx.h"
#include "WPoint.h"


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
