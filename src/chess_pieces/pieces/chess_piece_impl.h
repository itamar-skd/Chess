#ifndef __CHESS_PIECE_IMPL_H__
#define __CHESS_PIECE_IMPL_H__

#include "chess_piece.h"

class ChessPieceImpl : public IChessPiece
{
    public:
        ChessPieceImpl(Position pos, bool is_enemy) : _pos(pos), _is_enemy(is_enemy) {}
        ~ChessPieceImpl() = default;

    public:
        virtual bool can_move_to(Position pos) = 0;
        virtual bool move(Position pos) = 0;

    protected:
        bool _is_enemy;
        Position _pos;
};

#endif /* __CHESS_PIECE_IMPL_H__ */