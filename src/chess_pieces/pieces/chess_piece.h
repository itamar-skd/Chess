#ifndef __CHESS_PIECE_H__
#define __CHESS_PIECE_H__

#include "position.h"
#include <cstdint>
#include <array>

class IChessPiece
{
    public:
        virtual bool can_move_to(Position pos) = 0;
        virtual bool move(Position pos) = 0;
};

#endif /* __CHESS_PIECE_H__ */