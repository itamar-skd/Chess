#ifndef __BISHOP_PIECE_H__
#define __BISHOP_PIECE_H__

#include "chess_piece_impl.h"

class BishopPiece final : public ChessPieceImpl
{
    public:
        BishopPiece(Position pos, bool is_enemy) : ChessPieceImpl(pos, is_enemy) {}
        ~BishopPiece() = default;

    public:
        bool can_move_to(Position pos) override;
        bool move(Position pos) override;
};

#endif /* __BISHOP_PIECE_H__ */