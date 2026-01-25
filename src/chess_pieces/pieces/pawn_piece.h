#ifndef __PAWN_PIECE_H__
#define __PAWN_PIECE_H__

#include "chess_piece.h"

class PawnPiece final : IChessPiece
{
    public:
        PawnPiece(bool is_enemy);
        ~PawnPiece() = default;

    protected:
        bool _can_move_to(uint32_t x, uint32_t y);

    public:
        bool move(uint32_t x, uint32_t y);
};

#endif /* __PAWN_PIECE_H__ */