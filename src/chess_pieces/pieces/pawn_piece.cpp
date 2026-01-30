#include "pawn_piece.h"
#include <cmath>

PawnPiece::PawnPiece(Position pos)
    : ChessPieceImpl(E_ChessPiece::PAWN, pos)
{
    
}

bool PawnPiece::can_move_to(Position pos)
{
    if (pos.x >= CHESS_BOARD_SIZE || pos.y >= CHESS_BOARD_SIZE)
        return false;

    // A pawn moves only forwards when not trying to capture OR diagonally when capturing
    if (this->_pos.x != pos.x)
    {
        if ((abs(this->_pos.x - pos.x) == 1) && pos.y - this->_pos.y == 1)
            return true;

        return false;
    }

    if (pos.y - this->_pos.y == 1)
        return true;

    if (pos.y - this->_pos.y == 2 && this->_is_first)
        return true;

    return false;
}

std::vector<Position> PawnPiece::all_possible_moves()
{
    std::vector<Position> locations;

    if (this->_is_first)
    {
        for (int dy = 1; dy <= 2; dy++)
        {
            Position cur(this->_pos.x, this->_pos.y + dy);
            if (can_move_to(cur))
                locations.push_back(cur);
        }
        return locations;
    }

    for (int dx = -1; dx <= 1; dx++)
    {
        Position cur(this->_pos.x + dx, this->_pos.y + 1);
        if (can_move_to(cur))
            locations.push_back(cur);
    }

    return locations;
}