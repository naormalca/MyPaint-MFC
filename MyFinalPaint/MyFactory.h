#pragma once
#include"MyShape.h"
class MyFactory {
public:
	//return object from other class
	virtual MyShape* create() = 0;

};