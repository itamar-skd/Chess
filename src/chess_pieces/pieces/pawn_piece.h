#ifndef __PAWN_PIECE_H__
#define __PAWN_PIECE_H__

#include "chess_piece_impl.h"

class PawnPiece final : public ChessPieceImpl
{
    public:
        PawnPiece(Position pos, bool is_enemy);
        ~PawnPiece() = default;

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

    private:
        bool __is_first;
};

#endif /* __PAWN_PIECE_H__ */