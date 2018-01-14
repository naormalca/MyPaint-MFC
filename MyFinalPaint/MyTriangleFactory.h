#pragma once
#include "MyFactory.h"
#include "MyTriangle.h"
class MyTriangleFactory : public MyFactory {
	MyShape* create() {
		return new MyTriangle();
	}
};