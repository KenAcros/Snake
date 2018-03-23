#pragma once
#include "Position.h"
#include "Screen.h"
class Pellets
{
public:
	Pellets();

	Position getPos();
	void newPos(Screen & screen);
	
private:
	Position pos;
};

