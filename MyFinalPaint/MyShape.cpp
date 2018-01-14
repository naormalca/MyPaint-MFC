#include "stdafx.h"
#include "MyShape.h"
IMPLEMENT_SERIAL(MyShape, CObject, 1)
//C`stor
MyShape::MyShape(){
	backgroundColor = RGB(30, 200, 20);
	lineColor = RGB(0, 100, 0);
	borderSize = 3;
}
//Setters
void MyShape::setBegin(const MyPoint &p) { begin = p; }
void MyShape::setEnd(const MyPoint &p) { end = p; }
void MyShape::setBackgroundColor(COLORREF bColor)
{
	backgroundColor = bColor;
}
void MyShape::setLineColor(COLORREF lColor) {
	lineColor = lColor;
}
void MyShape::setBorderSize(int s) { borderSize = s; }
//Getters
MyPoint MyShape::getEnd() { return end; }
MyPoint MyShape::getBegin() { return begin; }
COLORREF MyShape::getBackgroundColor()
{
	return backgroundColor;
}
COLORREF MyShape::getLineColor()
{
	return lineColor;
}
void MyShape::draw(CDC &dc) {
	CPen pen(PS_SOLID, borderSize, lineColor);
	CBrush brush(backgroundColor);
	CPen *oldPen = dc.SelectObject(&pen);
	CBrush *oldBrush = dc.SelectObject(&brush);
	drawShape(dc);	
	dc.SelectObject(oldPen);
	dc.SelectObject(oldBrush);
	
}

//serialize the class data to archive,save and load
void MyShape::Serialize(CArchive & archive)
{
	//base class calling
	CObject::Serialize(archive);

	//isStoring return true if mfc try to save,false if load
	if (archive.IsStoring()) {
		archive << begin.getX() << begin.getY() << end.getX() << end.getY() << backgroundColor << lineColor << borderSize;
	}
	else {
		int beginX, beginY, endX, endY;
		//recive data from archive
		archive >> beginX >> beginY >> endX >> endY >> backgroundColor >> lineColor >> borderSize;
		//assign to begin and end
		begin.setX(beginX);
		begin.setY(beginY);
		end.setX(endX);
		end.setY(endY);
	}

}
//Operator =
const MyShape & MyShape::operator=(const MyShape & other)
{

	this->begin = other.begin;
	this->end = other.end;
	this->lineColor = other.lineColor;
	this->backgroundColor = other.backgroundColor;
	this->borderSize = other.borderSize;
	return (*this);

}
