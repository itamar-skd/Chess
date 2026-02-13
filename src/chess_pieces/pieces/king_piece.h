#ifndef __KING_PIECE_H__
#define __KING_PIECE_H__

#include "chess_piece_impl.h"

class KingPiece final : public ChessPieceImpl
{
    public:
        KingPiece(Position pos);
        ~KingPiece() = default;

    public:
        /**
         * @brief checks if the piece can be moved to a given position
         *        Important notice for king: does not consider castling rules. Those must be checked by the chess manager.
         *        This function will still return true if the given position is a castling position.
         * @returns true if the piece can be moved to that position, false otherwise
         */
        bool can_move_to(Position pos) override;

        /**
         * @brief get all the possible moves a piece can make.
         *        Important notice for king: does not consider castling rules. Those must be checked by the chess manager.
         *        This function will still return the two castling positions as possible moves.
         * @returns all possible locations
         */
        std::vector<Position> all_possible_moves() override;

        /**
         * @brief get a drawing of the piece
         * @returns a string of the piece's drawing
         */
        const std::vector<std::string>& drawing() const override;
};

#endif /* __KING_PIECE_H__ */