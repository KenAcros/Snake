#pragma once
#include <vector>
#include "stdafx.h"
#include "position.h"

using namespace std;

class Player
{
public:
	Player();

	std::vector<Position>& getBody();
	void move(char input, vector<vector<int>> & board);

private :
	std::vector<Position> body = std::vector<Position>();
};

