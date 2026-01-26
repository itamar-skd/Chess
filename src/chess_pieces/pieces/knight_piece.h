#ifndef __KNIGHT_PIECE_H__
#define __KNIGHT_PIECE_H__

#include "chess_piece_impl.h"

class KnightPiece final : public ChessPieceImpl
{
    public:
        KnightPiece(uint32_t x, uint32_t y, bool is_enemy) : ChessPieceImpl(x, y, is_enemy) {}
        ~KnightPiece() = default;

public:
        bool can_move_to(uint32_t x, uint32_t y);
        bool move(uint32_t x, uint32_t y);
};

#endif /* __KNIGHT_PIECE_H__ */