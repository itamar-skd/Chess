#ifndef __KING_PIECE_H__
#define __KING_PIECE_H__

#include "chess_piece_impl.h"

class KingPiece final : public ChessPieceImpl
{
    public:
        KingPiece(uint32_t x, uint32_t y, bool is_enemy) : ChessPieceImpl(x, y, is_enemy) {}
        ~KingPiece() = default;

public:
        bool can_move_to(uint32_t x, uint32_t y);
        bool move(uint32_t x, uint32_t y);
};

#endif /* __KING_PIECE_H__ */