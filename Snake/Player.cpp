#include "stdafx.h"
#include "Player.h"


Player::Player()
{
}

std::vector<Position>& Player::getBody()
{
	return body;
}

void Player::move(char input)
{
	std::vector<Position> newBody;
	Position head;
	switch (input)
	{
	case 'w':
		head = Position(body[0].getX, body[0].getY - 1);
		break;
	case 'a':
		head = Position(body[0].getX - 1, body[0].getY);
		break;
	case 's':
		head = Position(body[0].getX, body[0].getY + 1);
		break;
	case 'd':
		head = Position(body[0].getX + 1, body[0].getY);
		break;
	default:
		break;
	}
	if (!(std::find(body.begin(), body.end(), head) != body.end()) )
	{
		
	}
}
