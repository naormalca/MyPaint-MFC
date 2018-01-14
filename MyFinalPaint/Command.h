#pragma once
class Command
{
public:
	virtual void perform() = 0;
	virtual void rollback() = 0;

};