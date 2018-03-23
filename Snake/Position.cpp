#include "stdafx.h"
#include "position.h"

Position::Position()
{
    x = 0;
    y = 0;
}

Position::Position(int x_, int y_)
{
    x = x_;
    y = y_;
}

void Position::update(int x_, int y_)
{
    x = x_;
    y = y_;
}

int Position::getX()
{
    return x;
}

int Position::getY()
{
    return y;
}
