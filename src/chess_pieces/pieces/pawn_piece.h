#ifndef __PAWN_PIECE_H__
#define __PAWN_PIECE_H__

#include "chess_piece_impl.h"

class PawnPiece final : public ChessPieceImpl
{
    public:
        PawnPiece(Position pos, bool is_enemy);
        ~PawnPiece() = default;

    public:
        bool can_move_to(Position pos) override;
        bool move(Position pos) override;

    private:
        bool __is_first;
};

#endif /* __PAWN_PIECE_H__ */