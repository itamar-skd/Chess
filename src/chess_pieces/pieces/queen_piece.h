#ifndef __QUEEN_PIECE_H__
#define __QUEEN_PIECE_H__

#include "chess_piece_impl.h"

class QueenPiece final : public ChessPieceImpl
{
    public:
        QueenPiece(Position pos);
        ~QueenPiece() = default;

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

        /**
         * @brief get a drawing of the piece
         * @returns a string of the piece's drawing
         */
        const char* drawing() const override;
};

#endif /* __QUEEN_PIECE_H__ */