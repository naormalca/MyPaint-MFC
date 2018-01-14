#pragma once
#include "MyFactory.h"
#include "MyRectangle.h"
class MyRectangleFactory : public MyFactory {
	MyShape* create() {
		return new MyRectangle();
	}
	
};