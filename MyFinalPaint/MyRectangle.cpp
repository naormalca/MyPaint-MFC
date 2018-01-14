#include "stdafx.h"
#include "MyRectangle.h"
IMPLEMENT_SERIAL(MyRectangle, MyShape, 1)
void MyRectangle::drawShape(CDC &dc) {
		dc.Rectangle(begin.getX(), begin.getY(), end.getX(), end.getY());
}
bool MyRectangle::pointIsIn(CPoint &point) {
	//create new CReact and use contains method(mfc standart)
	CRect temp;
	temp.SetRect(begin.getX(), begin.getY(), end.getX(), end.getY());
	return temp.PtInRect(point);
}

