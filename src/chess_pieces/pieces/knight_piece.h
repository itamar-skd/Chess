#ifndef __KNIGHT_PIECE_H__
#define __KNIGHT_PIECE_H__

#include "chess_piece_impl.h"

class KnightPiece final : public ChessPieceImpl
{
    public:
        KnightPiece(Position pos);
        ~KnightPiece() = default;

    public:
        /**
         * @brief checks if the piece can be moved to a given position
         * @returns true if the piece can be moved to that position, false otherwise
         */
        bool can_move_to(Position pos) override;

        /**
         * @brief get all the possible moves a piece can make
         * @returns all possible locations
         */
        std::vector<Position> all_possible_moves() override;
};

#endif /* __KNIGHT_PIECE_H__ */