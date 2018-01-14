#pragma once

class MyPoint {
public:
	//C`stor
	MyPoint(int x = 0 ,int y =0) : x(x), y(y) {}
	
	//Getters
	int getX() const;
	int getY() const;
	//Setters
	void setX(int x);
	void setY(int y);
	//add amount for movement function 
	void addX(int amount);
	void addY(int amount);
private:
	int x, y;
};