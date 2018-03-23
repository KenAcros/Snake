#pragma once
#ifndef SCREEN_H
#define SCREEN_H

#include <string>
#include "Position.h"
#include "windows.h"


class Screen
{
public:
	Screen();
	Screen(int, int);
	Screen(int, int, bool);
	void setSize(int, int);
	void setCharAt(char, int, char = '\0');
	void setCharAt(char, int, int, char = '\0');
	void setCharAt(char, Position&, char = '\0');
	void setCharAt(std::string, int, int);
	void clearScreen();
	Position indexToPosition(int) const;
	int positionToIndex(Position&) const;
	int getWidth();
	int getHeight();
	void display();



protected:

private:
	int width, height;
	bool useSquareScreen;
	std::string screenContent;
};

#endif // SCREEN_H