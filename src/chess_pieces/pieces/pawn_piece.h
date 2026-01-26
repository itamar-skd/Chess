#ifndef __PAWN_PIECE_H__
#define __PAWN_PIECE_H__

#include "chess_piece_impl.h"

class PawnPiece final : public ChessPieceImpl
{
    public:
        PawnPiece(uint32_t x, uint32_t y, bool is_enemy) : ChessPieceImpl(x, y, is_enemy) {}
        ~PawnPiece() = default;

    protected:
        bool _can_move_to(uint32_t x, uint32_t y);

    public:
        bool move(uint32_t x, uint32_t y);
};

#endif /* __PAWN_PIECE_H__ */