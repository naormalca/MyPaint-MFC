#pragma once
#include "Command.h"
#include "MyShape.h"
#include <vector>

using namespace std;

class AddCommand:public Command
{
public:
	AddCommand(vector<MyShape*>&shapes, MyShape *shape);
	void perform();

	void rollback();

private:
	vector<MyShape*>&shapes;
	MyShape *shape;

};