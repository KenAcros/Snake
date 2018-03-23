#include "stdafx.h"
#include "Pellets.h"
#include "Screen.h"

using namespace std;

Pellets::Pellets()
{
}

Position Pellets::getPos()
{
	return pos;
}

void Pellets::newPos(vector<vector<int>> & board)
{
	pos.update(rand() % board.size(),rand() % board[0].size());
}
