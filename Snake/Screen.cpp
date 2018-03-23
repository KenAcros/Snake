#include "stdafx.h"
#include "Screen.h"
#include <iostream>

// Create a screen using console width and height using square pixels
Screen::Screen()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	int columns, rows;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	columns = csbi.srWindow.Right - csbi.srWindow.Left;
	rows = csbi.srWindow.Bottom - csbi.srWindow.Top;

	if (columns % 2 != 0) {
		columns--;
	}

	useSquareScreen = true;

	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < columns; ++j) {
			screenContent.append(" ");
		}
		screenContent.append("\n");
	}

	width = columns;
	height = rows;
}

Screen::Screen(int w, int h, bool b = false)
{
	useSquareScreen = b;

	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			screenContent.append(" ");
		}
		screenContent.append("\n");
	}
	width = w;
	height = h;
}

void Screen::display() {
	std::cout << screenContent;
}

void Screen::setSize(int w, int h)
{
	// TODO: Stuff
	width = w;
	height = h;
}

void Screen::setCharAt(char c, int i, char d)
{
	if (d == '\0') d = c;

	if (useSquareScreen) {
		int newLineCount = (i * 2) / width;
		screenContent[i * 2 + newLineCount] = c;
		screenContent[i * 2 + newLineCount + 1] = d;
	}
	else {
		int newLineCount = (i / width);
		screenContent[i + newLineCount] = c;
	}
}

void Screen::setCharAt(char c, Position &p, char d)
{
	setCharAt(c, positionToIndex(p), d);
}

void Screen::setCharAt(char c, int x, int y, char d)
{
	Position p(x, y);
	setCharAt(c, p, d);
}

void Screen::setCharAt(std::string s, int x, int y) {
	int defaultX = x;

	if (useSquareScreen) {
		for (int i = 0; i < s.length(); i += 2) {
			if (s.at(i) == '\'') {
				y++;
				i--;
				x = defaultX;
			}
			else {
				if (s.at(i + 1) != '\'') {
					setCharAt(s.at(i), x++, y, s.at(i + 1));
				}
				else {
					setCharAt(s.at(i), x++, y, ' ');
					i--;
				}
			}
		}
	}
	else {
		for (int i = 0; i < s.length(); i++) {
			if (s.at(i) == '\'') {
				y++;
				x = defaultX;
			}
			else {
				setCharAt(s.at(i), x++, y);
			}
		}
	}
}

int Screen::getWidth() {
	if (useSquareScreen) return width / 2;
	else return width;
}

int Screen::getHeight() {
	return height;
}

void Screen::clearScreen() {
	for (int i = 0; i < width; ++i) {
		for (int j = 0; j < height; ++j) {
			setCharAt(' ', i, j);
		}
	}
}

// This does not include new lines!
int Screen::positionToIndex(Position& p) const
{
	if (useSquareScreen) {
		return p.getX() + p.getY() * width / 2;
	}
	else {
		return p.getX() + p.getY() * width;
	}
}

Position Screen::indexToPosition(int i) const
{
	return Position();
}

