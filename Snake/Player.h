#pragma once
#include <vector>
#include "stdafx.h"
#include "position.h"
class Player
{
public:
	Player();

	std::vector<Position>& getBody();

private :
	std::vector<Position> body = std::vector<Position>();
};

