// Snake.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include "Screen.h"
#include "Pellets.h"
#include "Player.h"
#include "vector"

using namespace std;

void initBoard(Screen & screen, vector<vector<int>> & board);
void displayBoard(vector<vector<int>> & board, Screen & screen);

int main()
{
	Screen screen;
	Player snake;
	vector<vector<int>> board;
	bool on = true;
	initBoard(screen, board);
	displayBoard(board, screen);
	while (on)
	{
		if (GetAsyncKeyState(87))
		{
			snake.move('w', board);
		}
		if (GetAsyncKeyState(65))
		{
			snake.move('a', board);
		}
		if (GetAsyncKeyState(83))
		{
			snake.move('s', board);
		}
		if (GetAsyncKeyState(68))
		{
			snake.move('d', board);
		}
		if (GetAsyncKeyState(27))
		{
			on = false;
		}
		displayBoard(board, screen);
	}
	return 0;
}

void initBoard(Screen & screen, vector<vector<int>> & board)
{
	try
	{
		int width = screen.getWidth() - 1;
		int height = screen.getHeight() - 1;
		board.resize(width);
		//Wall on the top and bottom
		for (int i = 0; i < width; i++)
		{
			board[i].resize(height + 1);
			board[i][0] = 1;
			board[i][height - 1] = 1;
		}
		//Wall on the left and right
		for (int i = 0; i < height; i++)
		{
			board[0][i] = 1;
			board[width - 1][i] = 1;
		}
	}
	catch (exception e) {}
}
void displayBoard(vector<vector<int>> & board, Screen & screen)
{
	int width = screen.getWidth() - 1;
	int height = screen.getHeight() - 1;
	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
		{
			switch (board[x][y])
			{
			case 0:
				screen.setCharAt(0, x, y);
				break;
			case 1:
				screen.setCharAt(219, x, y);
				break;
			case 2:
				screen.setCharAt(178, x, y);
				break;
			case 3:
				screen.setCharAt(233, x, y);
				break;
			default:
				break;
			}
		}
	}
	screen.display();
}


