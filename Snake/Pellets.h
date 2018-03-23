#pragma once
#include "Position.h"
#include "Screen.h"
#include <vector>

using namespace std;
class Pellets
{
public:
	Pellets();

	Position getPos();
	void newPos(vector<vector<int>> & board);
	
private:
	Position pos;
};

