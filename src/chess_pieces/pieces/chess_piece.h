#ifndef __CHESS_PIECE_H__
#define __CHESS_PIECE_H__

#include "position.h"
#include "game_defines.h"
#include <cstdint>
#include <vector>

class IChessPiece
{
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
        virtual bool move(Position pos) = 0;

        /**
         * @brief get all the possible moves a piece can make
         * @returns all possible locations
         */
        virtual std::vector<Position> all_possible_moves() = 0;

        /**
         * @brief check if this piece has moved at least once
         * @returns true if the piece has moved, false otherwise
         */
        virtual bool has_moved() const = 0;

        /**
         * @brief check if this piece belongs to the enemy. enemies are assigned by the constructor if their y-coordinate is smaller than half the chess board's height
         * @returns true if the piece is an enemy, false otherwise
         */
        virtual const bool is_enemy() const = 0;

        /**
         * @brief check this piece's role, see E_ChessPiece
         * @returns the piece's role
         */
        virtual E_ChessPiece kind() const = 0;
};

#endif /* __CHESS_PIECE_H__ */