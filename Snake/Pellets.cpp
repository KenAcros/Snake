#include "stdafx.h"
#include "Pellets.h"
#include "Screen.h"


Pellets::Pellets()
{
}

Position Pellets::getPos()
{
	return pos;
}

void Pellets::newPos(Screen &screen)
{
	pos.update(rand() % screen.getWidth,rand() % screen.getHeight);	
}
