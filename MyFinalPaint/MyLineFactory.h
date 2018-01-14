#pragma once
#include "MyFactory.h"
#include "MyLine.h"
class MyLineFactory : public MyFactory {
	MyShape* create() {
		return new MyLine();
	}
};