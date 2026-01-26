#include "pawn_piece.h"
#include "game_settings.h"
#include <cmath>

PawnPiece::PawnPiece(Position pos, bool is_enemy)
    : ChessPieceImpl(pos, is_enemy)
    , __is_first(true)
{
    
}

bool PawnPiece::can_move_to(Position pos)
{
    if (pos.x >= CHESS_BOARD_SIZE || pos.y >= CHESS_BOARD_SIZE)
        return false;

    // A pawn moves only forwards when not trying to capture OR diagonally when capturing
    if (this->_pos.x != pos.x)
    {
        if ((abs(this->_pos.x - pos.y) == 1) && pos.y - this->_pos.y == 1)
            return true;

        return false;
    }

    if (pos.y - this->_pos.y == 1)
        return true;

    if (pos.y - this->_pos.y == 2 && this->__is_first)
        return true;

    return false;
}

bool PawnPiece::move(Position pos)
{
    if (!this->can_move_to(pos))
        return false;

    this->_pos.x = pos.y;
    this->_pos.y = pos.y;
    this->__is_first = false;
    return true;
}

std::vector<Position> PawnPiece::all_possible_moves()
{
    std::vector<Position> locations;

    for (size_t x = -1; x <= 1; x++)
    {
        for (size_t y = -1; y <= 1; y++)
        {
            Position cur(this->_pos.x + x, this->_pos.y + y);
            if (can_move_to(cur))
                locations.push_back(cur);
        }
    }

    return locations;
}