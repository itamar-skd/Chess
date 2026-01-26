#ifndef __QUEEN_PIECE_H__
#define __QUEEN_PIECE_H__

#include "chess_piece_impl.h"

class QueenPiece final : public ChessPieceImpl
{
    public:
        QueenPiece(Position pos, bool is_enemy) : ChessPieceImpl(pos, is_enemy) {}
        ~QueenPiece() = default;

    public:
        bool can_move_to(Position pos) override;
        bool move(Position pos) override;
};

#endif /* __QUEEN_PIECE_H__ */