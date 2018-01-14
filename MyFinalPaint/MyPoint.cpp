#include "stdafx.h"
#include "MyPoint.h"


//Getters
int MyPoint::getX() const { return x; }
int MyPoint::getY() const { return y; }
//Setters
void MyPoint::setX(int x) { this->x = x; }
void MyPoint::setY(int y) { this->y = y; }
void MyPoint::addX(int amount) { this->x = x + amount; }
void MyPoint::addY(int amount) { this->y = y + amount; }