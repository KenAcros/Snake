#include "stdafx.h"
#include "Player.h"


Player::Player()
{
	body.push_back(Position(10, 10)); //TODO chnage this to avoid magic numbers
}

std::vector<Position>& Player::getBody()
{
	return body;
}

void Player::move(char input, vector<vector<int>> & board)
{
	for (Position &pos : body)
	{
		board[pos.getX()][pos.getY()] = 0;
	}
	std::vector<Position> newBody;
	Position head;
	switch (input)
	{
	case 'w':
		head = Position(body[0].getX(), body[0].getY() - 1);
		break;
	case 'a':
		head = Position(body[0].getX() - 1, body[0].getY());
		break;
	case 's':
		head = Position(body[0].getX(), body[0].getY() + 1);
		break;
	case 'd':
		head = Position(body[0].getX() + 1, body[0].getY());
		break;
	default:
		break;
	}

	int headCollision = board[head.getX()][head.getY()];
	if (headCollision == 0)
		for (int i = 0; i < body.size(); i++)
		{
			newBody.push_back(head);
			for (int i = 0; i < body.size() - 1; i++)
			{
				newBody.push_back(body[i]);
			}
			body = newBody;
		}
	else if (headCollision == 3)
	{
		for (int i = 0; i < body.size(); i++)
		{
			newBody[0] = head;
			for (int i = 0; i < body.size(); i++)
			{
				newBody.push_back(body[i]);
			}
			body = newBody;
		}
	}
	for (Position &pos : body)
	{
		board[pos.getX()][pos.getY()] = 2;
	}
}
