#pragma once

#include "MyShape.h"

class MyLine : public MyShape {
	DECLARE_SERIAL(MyLine)
	void drawShape(CDC &dc);
	bool MyLine::pointIsIn(CPoint &point);
};
