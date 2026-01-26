#ifndef __ROOK_PIECE_H__
#define __ROOK_PIECE_H__

#include "chess_piece_impl.h"

class RookPiece final : public ChessPieceImpl
{
    public:
        RookPiece(uint32_t x, uint32_t y, bool is_enemy) : ChessPieceImpl(x, y, is_enemy) {}
        ~RookPiece() = default;

    public:
        bool can_move_to(uint32_t x, uint32_t y) override;
        bool move(uint32_t x, uint32_t y) override;
};

#endif /* __ROOK_PIECE_H__ */