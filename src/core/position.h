#ifndef __POSITION_H__
#define __POSITION_H__

#include <cstdint>

struct Direction {
    int16_t x;
    int16_t y;

    Direction(int16_t x, int16_t y) : x(x), y(y) {}
    Direction operator*(double value) const
    {
        return Direction(x * value, y * value);
    }
};

struct Position {
    uint16_t x;
    uint16_t y;

    Position(uint16_t x, uint16_t y) : x(x), y(y) {}
    bool operator==(const Position& other) const
    {
        return x == other.x && y == other.y;
    }

    void operator+=(const Direction& dir)
    {
        x += dir.x;
        y += dir.y;
    }
};

#endif /* __POSITION_H__ */