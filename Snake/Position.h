#pragma once
#ifndef POSITION_H
#define POSITION_H


class Position
{
    public:
        Position();
        Position(int, int);
        void update(int, int);
        int getX();
        int getY();
		bool operator==(Position &a);
    private:
        int x, y;
};

#endif // POSITION_H
