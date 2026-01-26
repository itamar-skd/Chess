#ifndef __BISHOP_PIECE_H__
#define __BISHOP_PIECE_H__

#include "chess_piece_impl.h"

class BishopPiece final : public ChessPieceImpl
{
    public:
        BishopPiece(Position pos, bool is_enemy) : ChessPieceImpl(pos, is_enemy) {}
        ~BishopPiece() = default;

    public:
        /**
         * @brief checks if the piece can be moved to a given position
         * @returns true if the piece can be moved to that position, false otherwise
         */
        bool can_move_to(Position pos) override;

        /**
         * @brief moves the piece to a given position if possible
         * @returns true if the piece was moved, false otherwise (see can_move_to)
         */
        bool move(Position pos) override;

        /**
         * @brief get all the possible moves a piece can make
         * @returns all possible locations
         */
        std::vector<Position> all_possible_moves() override;
};

#endif /* __BISHOP_PIECE_H__ */