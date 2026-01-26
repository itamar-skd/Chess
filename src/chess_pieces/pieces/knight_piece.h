#ifndef __KNIGHT_PIECE_H__
#define __KNIGHT_PIECE_H__

#include "chess_piece_impl.h"

class KnightPiece final : public ChessPieceImpl
{
    public:
        KnightPiece(Position pos, bool is_enemy) : ChessPieceImpl(pos, is_enemy) {}
        ~KnightPiece() = default;

    public:
        bool can_move_to(Position pos) override;
        bool move(Position pos) override;
};

#endif /* __KNIGHT_PIECE_H__ */