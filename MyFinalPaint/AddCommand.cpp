#include "stdafx.h"
#include "AddCommand.h"

AddCommand::AddCommand(vector<MyShape*>&shapes, MyShape *shape)
	: shapes(shapes), shape(shape) {}


void AddCommand::perform()
{
	shapes.push_back(shape);
}

void AddCommand::rollback()
{

	vector<MyShape*>::iterator it;
	for (it = shapes.begin(); it != shapes.end(); ++it)
		if (*it == shape)
			break;

	if (it != shapes.end())
		shapes.erase(it);
}