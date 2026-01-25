#ifndef __ROOK_PIECE_H__
#define __ROOK_PIECE_H__

#include "chess_piece.h"

class QueenPiece final : IChessPiece
{
    public:
        QueenPiece(bool is_enemy);
        ~QueenPiece() = default;

    protected:
        bool _can_move_to(uint32_t x, uint32_t y);

    public:
        bool move(uint32_t x, uint32_t y);
};

#endif /* __ROOK_PIECE_H__ */