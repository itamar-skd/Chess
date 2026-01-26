#ifndef __PAWN_PIECE_H__
#define __PAWN_PIECE_H__

#include "chess_piece_impl.h"

class PawnPiece final : public ChessPieceImpl
{
    public:
        PawnPiece(uint32_t x, uint32_t y, bool is_enemy);
        ~PawnPiece() = default;

    public:
        bool can_move_to(uint32_t x, uint32_t y);
        bool move(uint32_t x, uint32_t y);

    private:
        bool __is_first;
};

#endif /* __PAWN_PIECE_H__ */