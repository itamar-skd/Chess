#ifndef __BISHOP_PIECE_H__
#define __BISHOP_PIECE_H__

#include "chess_piece.h"

class BishopPiece final : public IChessPiece
{
    public:
        BishopPiece(bool is_enemy);
        ~BishopPiece() = default;

    protected:
        bool _can_move_to(uint32_t x, uint32_t y);

    public:
        bool move(uint32_t x, uint32_t y);
};

#endif /* __BISHOP_PIECE_H__ */