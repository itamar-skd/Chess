#ifndef __CHESS_PIECE_H__
#define __CHESS_PIECE_H__

#include <cstdint>

class IChessPiece
{
    public:
        virtual bool can_move_to(uint32_t x, uint32_t y) = 0;
        virtual bool move(uint32_t x, uint32_t y) = 0;
};

#endif /* __CHESS_PIECE_H__ */