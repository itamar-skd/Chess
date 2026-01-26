#ifndef __QUEEN_PIECE_H__
#define __QUEEN_PIECE_H__

#include "chess_piece_impl.h"

class QueenPiece final : public ChessPieceImpl
{
    public:
        QueenPiece(uint32_t x, uint32_t y, bool is_enemy) : ChessPieceImpl(x, y, is_enemy) {}
        ~QueenPiece() = default;

    public:
        bool can_move_to(uint32_t x, uint32_t y) override;
        bool move(uint32_t x, uint32_t y) override;
};

#endif /* __QUEEN_PIECE_H__ */