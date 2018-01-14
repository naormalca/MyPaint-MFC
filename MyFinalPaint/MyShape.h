#pragma once
#include "stdafx.h"
#include "MyPoint.h"

class MyShape : public CObject{
	DECLARE_SERIAL(MyShape)
public:
	MyShape();
	//Setters
	void setBegin(const MyPoint &p);
	void setEnd(const MyPoint &p);
	void setBackgroundColor(COLORREF);
	void setLineColor(COLORREF lineColor);
	void setBorderSize(int s);
	const MyShape & operator=(const MyShape &other);
	//Getters
	MyPoint getEnd();
	MyPoint getBegin();
	COLORREF getBackgroundColor();
	COLORREF getLineColor();
	virtual void drawShape(CDC &dc) {}
	void draw(CDC &dc);
	virtual bool pointIsIn(CPoint &dc) { return false; };
	void Serialize(CArchive& archive);

protected:
	MyPoint begin, end;
	COLORREF backgroundColor, lineColor;
	int borderSize;
};