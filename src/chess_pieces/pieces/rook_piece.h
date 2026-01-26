#ifndef __ROOK_PIECE_H__
#define __ROOK_PIECE_H__

#include "chess_piece_impl.h"

class RookPiece final : public ChessPieceImpl
{
    public:
        RookPiece(bool is_enemy);
        ~RookPiece() = default;

    protected:
        bool _can_move_to(uint32_t x, uint32_t y);

    public:
        bool move(uint32_t x, uint32_t y);
};

#endif /* __ROOK_PIECE_H__ */