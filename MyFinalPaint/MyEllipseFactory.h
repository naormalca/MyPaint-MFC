#pragma once
#include "MyFactory.h"
#include "MyEllipse.h"
class MyEllipseFactory : public MyFactory {
	MyShape* create() {
		return new MyEllipse();
	}
};