#ifndef __KING_PIECE_H__
#define __KING_PIECE_H__

#include "chess_piece.h"

class KingPiece final : public IChessPiece
{
    public:
        KingPiece(bool is_enemy);
        ~KingPiece() = default;

    protected:
        bool _can_move_to(uint32_t x, uint32_t y);

    public:
        bool move(uint32_t x, uint32_t y);
};

#endif /* __KING_PIECE_H__ */