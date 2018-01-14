#pragma once
#include "MyShape.h"
class MyTriangle : public MyShape
{
	DECLARE_SERIAL(MyTriangle)
public:
	void drawShape(CDC &dc);
	bool pointIsIn(CPoint &point);
	
private:
	MyPoint midPoint;
};

