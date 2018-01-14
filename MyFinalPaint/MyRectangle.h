#pragma once
#include "MyShape.h"

class MyRectangle : public MyShape {
	DECLARE_SERIAL(MyRectangle)
	void drawShape(CDC &dc);
	bool pointIsIn(CPoint &point);
};