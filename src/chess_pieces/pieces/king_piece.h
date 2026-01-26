#ifndef __KING_PIECE_H__
#define __KING_PIECE_H__

#include "chess_piece_impl.h"

class KingPiece final : public ChessPieceImpl
{
    public:
        KingPiece(Position pos, bool is_enemy) : ChessPieceImpl(pos, is_enemy) {}
        ~KingPiece() = default;

    public:
        bool can_move_to(Position pos) override;
        bool move(Position pos) override;
};

#endif /* __KING_PIECE_H__ */