#ifndef __KING_PIECE_H__
#define __KING_PIECE_H__

#include "chess_piece_impl.h"

class KingPiece final : public ChessPieceImpl
{
    public:
        KingPiece(uint32_t x, uint32_t y, bool is_enemy) : ChessPieceImpl(x, y, is_enemy) {}
        ~KingPiece() = default;

    public:
        bool can_move_to(uint32_t x, uint32_t y) override;
        bool move(uint32_t x, uint32_t y) override;
};

#endif /* __KING_PIECE_H__ */