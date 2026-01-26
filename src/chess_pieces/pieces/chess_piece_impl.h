#ifndef __CHESS_PIECE_IMPL_H__
#define __CHESS_PIECE_IMPL_H__

#include "chess_piece.h"

class ChessPieceImpl : public IChessPiece
{
    public:
        ChessPieceImpl(bool is_enemy) : _is_enemy(is_enemy) {}
        ~ChessPieceImpl() = default;

    protected:
        virtual bool _can_move_to(uint32_t x, uint32_t y) = 0;

    public:
        virtual bool move(uint32_t x, uint32_t y) = 0;

    protected:
        bool _is_enemy;
};

#endif /* __CHESS_PIECE_IMPL_H__ */