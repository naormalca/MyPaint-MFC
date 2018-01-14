#pragma once

#include "MyShape.h"

class MyEllipse : public MyShape {
	DECLARE_SERIAL(MyEllipse)
	void drawShape(CDC &dc);
	bool MyEllipse::pointIsIn(CPoint &point);
	
};