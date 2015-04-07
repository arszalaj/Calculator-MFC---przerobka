#pragma once
class WPoint : public CPoint
{
public:
	WPoint(void);
	WPoint(
		_In_ double initX,
		_In_ double initY) throw();
	~WPoint(void);
private:
	int dX;
	int dY;
};

