// Snake.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include "Screen.h"
#include "Pellets.h"
#include "Player.h"
#include "vector"

using namespace std;

void initBoard(vector<vector<int>> board, Screen & screen);
void displayBoard(vector<vector<int>> board, Screen & screen);

int main()
{
	Screen screen;
	vector<vector<int>> board;
	bool on = true;
	initBoard(board, screen);
	//displayBoard(board,screen);
	/*while (on)
	{

	}*/
	cin.get();
	return 0;
}

void initBoard(vector<vector<int>> board, Screen & screen)
{
	try 
	{
		int width = screen.getWidth() - 1;
		int height = screen.getHeight() - 1;
		board.resize(height + 1);
		//Wall on the top and bottom
		for (int i = 0; i < height; i++)
		{
			board[i].resize(width + 1);
			board[i][0] = 1;
			board[i][height] = 1;
		}
		//Wall on the left and right
		for (int i = 0; i < width; i++)
		{
			board[0][i] = 1;
			board[width][i] = 1;
		}
	}
	catch(exception e){}
}
void displayBoard(vector<vector<int>> board, Screen & screen)
{
	try
	{
		for (int i = 0; i < screen.getWidth() - 2; i++)
		{
			for (int j = 0; j < screen.getHeight() - 2; j++)
			{
				if (board[i][j] == 1)
				{
					screen.setCharAt('A', i, j);
				}
			}
		}
		screen.display();
	}
	catch (exception e) {}
}

