#ifndef __KNIGHT_PIECE_H__
#define __KNIGHT_PIECE_H__

#include "chess_piece.h"

class KnightPiece final : IChessPiece
{
    public:
        KnightPiece(bool is_enemy);
        ~KnightPiece() = default;

    protected:
        bool _can_move_to(uint32_t x, uint32_t y);

    public:
        bool move(uint32_t x, uint32_t y);
};

#endif /* __KNIGHT_PIECE_H__ */