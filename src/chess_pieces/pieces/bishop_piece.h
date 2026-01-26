#ifndef __BISHOP_PIECE_H__
#define __BISHOP_PIECE_H__

#include "chess_piece_impl.h"

class BishopPiece final : public ChessPieceImpl
{
    public:
        BishopPiece(uint32_t x, uint32_t y, bool is_enemy) : ChessPieceImpl(x, y, is_enemy) {}
        ~BishopPiece() = default;

public:
        bool can_move_to(uint32_t x, uint32_t y);
        bool move(uint32_t x, uint32_t y);
};

#endif /* __BISHOP_PIECE_H__ */