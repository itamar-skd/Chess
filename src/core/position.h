#ifndef __POSITION_H__
#define __POSITION_H__

#include <cstdint>

struct Position {
    uint16_t x;
    uint16_t y;

    Position(uint16_t x, uint16_t y) : x(x), y(y) {}
    bool operator==(const Position& other) const {
        return x == other.x && y == other.y;
    }
};

#endif /* __POSITION_H__ */