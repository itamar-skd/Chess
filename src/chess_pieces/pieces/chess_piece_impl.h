#ifndef __CHESS_PIECE_IMPL_H__
#define __CHESS_PIECE_IMPL_H__

#include "chess_piece.h"
#include <iostream>

class ChessPieceImpl : public IChessPiece
{
    public:
        ChessPieceImpl(E_ChessPiece kind, Position pos) : _kind(kind), _pos(pos), _is_enemy(pos.y < CHESS_BOARD_SIZE / 2), _is_first(true) {}
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

        /**
         * @brief check if this piece has moved at least once
         * @returns true if the piece has moved, false otherwise
         */
        inline bool has_moved() const override { return !this->_is_first; }

        /**
         * @brief check if this piece belongs to the enemy. enemies are assigned by the constructor if their y-coordinate is smaller than half the chess board's height
         * @returns true if the piece is an enemy, false otherwise
         */
        inline const bool is_enemy() const override { return this->_is_enemy; }

        /**
         * @brief check this piece's role, see E_ChessPiece
         * @returns the piece's role
         */
        inline E_ChessPiece kind() const override { return this->_kind; }

        /**
         * @brief get a drawing of the piece
         * @returns a string of the piece's drawing
         */
        const char* drawing() const = 0;

    protected:
        E_ChessPiece _kind;
        const bool _is_enemy;
        Position _pos;
        bool _is_first;
};

#endif /* __CHESS_PIECE_IMPL_H__ */