#ifndef __CHESS_PIECE_IMPL_H__
#define __CHESS_PIECE_IMPL_H__

#include "chess_piece.h"

class ChessPieceImpl : public IChessPiece
{
    public:
        ChessPieceImpl(Position pos, bool is_enemy) : _pos(pos), _is_enemy(is_enemy), _is_first(true) {}
        ~ChessPieceImpl() = default;

    public:
        /**
         * @brief checks if the piece can be moved to a given position
         * @returns true if the piece can be moved to that position, false otherwise
         */
        virtual bool can_move_to(Position pos) = 0;

        /**
         * @brief moves the piece to a given position if possible
         * @returns true if the piece was moved, false otherwise (see can_move_to)
         */
        bool move(Position pos) override
        {
            if (!this->can_move_to(pos))
                return false;

            this->_pos = pos;
            this->_is_first = false;
            return true;
        }

        /**
         * @brief get all the possible moves a piece can make
         * @returns all possible locations
         */
        virtual std::vector<Position> all_possible_moves() = 0;

        inline bool has_moved() const override { return !this->_is_first; }

    protected:
        bool _is_enemy;
        Position _pos;
        bool _is_first;
};

#endif /* __CHESS_PIECE_IMPL_H__ */