#include "stdafx.h"
#include "MyTriangle.h"
IMPLEMENT_SERIAL(MyTriangle, MyShape, 1)
void MyTriangle::drawShape(CDC &dc) {
	midPoint.setY(end.getY());
	midPoint.setX(begin.getX() - (end.getX() - begin.getX()));
	//from MyPoint to CPoint
	CPoint b,middle,e;
	middle.y = midPoint.getY();
	middle.x = midPoint.getX();
	b.x = begin.getX();
	b.y = begin.getY();
	e.x = end.getX();
	e.y = end.getY();
	CPoint p_arr[3] = { b,middle,e };
	dc.Polygon(p_arr,3);
	
}
bool MyTriangle::pointIsIn(CPoint &point) {
	int as_x = point.x - begin.getX();
	int as_y = point.y - begin.getY();
	
	bool s_ab = (midPoint.getX() - begin.getX()) * as_y - (midPoint.getY() - begin.getY()) * as_x > 0;
	if (((end.getX() - begin.getX()) * as_y - (end.getY() - begin.getY()) * as_x) > 0 == s_ab) 
		return false;
	if ((end.getX() - midPoint.getX()) * (point.y - midPoint.getY()) - (end.getY() - midPoint.getY()) * point.x - midPoint.getX()
		> 0 != s_ab)
		return false;
	return true;

}




