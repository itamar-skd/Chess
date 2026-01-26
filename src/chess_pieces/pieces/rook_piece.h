#ifndef __ROOK_PIECE_H__
#define __ROOK_PIECE_H__

#include "chess_piece_impl.h"

class RookPiece final : public ChessPieceImpl
{
    public:
        RookPiece(Position pos, bool is_enemy) : ChessPieceImpl(pos, is_enemy) {}
        ~RookPiece() = default;

    public:
        bool can_move_to(Position pos) override;
        bool move(Position pos) override;
};

#endif /* __ROOK_PIECE_H__ */