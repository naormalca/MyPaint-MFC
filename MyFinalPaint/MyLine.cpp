#include "stdafx.h"
#include "MyLine.h"
IMPLEMENT_SERIAL(MyLine, MyShape, 1)

void MyLine::drawShape(CDC &dc) {
	dc.MoveTo(begin.getX(), begin.getY());
	dc.LineTo(end.getX(), end.getY());
}
bool MyLine::pointIsIn(CPoint &point) {

	double d1 = (end.getY() - begin.getY()) *	point.x -
		(end.getX() - begin.getX()) * point.y +
		(end.getX()*begin.getY()) - end.getY() * begin.getX();

	double d2 = (end.getY() - begin.getY()) * (end.getY() - begin.getY()) +
		(end.getX() - begin.getX()) * (end.getX() - begin.getX());

	float dist = abs((int)d1) / sqrt(d2);

	if ((dist <= 0 && dist >= -10) || (dist >= 0 && dist <= 10))
		return true;

	return false;
}