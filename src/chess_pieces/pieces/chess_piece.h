#ifndef __CHESS_PIECE_H__
#define __CHESS_PIECE_H__

#include <cstdint>

class IChessPiece
{
    protected:
        virtual bool _can_move_to(uint32_t x, uint32_t y);
    public:
        virtual bool move(uint32_t x, uint32_t y);
};

#endif /* __CHESS_PIECE_H__ */