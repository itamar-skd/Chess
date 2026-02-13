#ifndef __ROOK_PIECE_H__
#define __ROOK_PIECE_H__

#include "chess_piece_impl.h"

class RookPiece final : public ChessPieceImpl
{
    public:
        RookPiece(Position pos);
        ~RookPiece() = default;

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
        const std::vector<std::string>& drawing() const override;
};

#endif /* __ROOK_PIECE_H__ */