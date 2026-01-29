#include "king_piece.h"
#include "game_settings.h"
#include <cmath>

bool KingPiece::can_move_to(Position pos)
{
    if (pos.x >= CHESS_BOARD_SIZE || pos.y >= CHESS_BOARD_SIZE)
        return false;

    // Castling - Whether the king can castle must be decide by the module that holds the chess board.
    // No piece on its own should be aware of its surroundings.
    if (this->_is_first)
    {
        if (abs(pos.x - this->_pos.x) == 2 && pos.y == this->_pos.y)
            return true;
    }

    if (abs(this->_pos.x - pos.x) <= 1 && abs(this->_pos.y - pos.y) <= 1)
        return true;

    return false;
}

bool KingPiece::move(Position pos)
{
    if (!this->can_move_to(pos))
        return false;

    this->_pos.x = pos.x;
    this->_pos.y = pos.y;
    this->_is_first = false;
    return true;
}

std::vector<Position> KingPiece::all_possible_moves()
{
    std::vector<Position> locations;

    // Castling - Whether the king can castle must be decide by the module that holds the chess board.
    // No piece on its own should be aware of its surroundings.
    if (this->_is_first)
    {
        for (int dx = -2; dx <= 2; dx += 4)
        {
            Position castling_pos(this->_pos.x + dx, this->_pos.y);
            if (this->can_move_to(castling_pos))
                locations.push_back(castling_pos);
        }
    }

    // The king can move one spot in any direction
    for (int dx = -1; dx <= 1; dx++)
    {
        for (int dy = -1; dy <= 1; dy++)
        {
            if (dx == 0 && dy == 0)
                continue;

            Position cur(this->_pos.x + dx, this->_pos.y + dy);
            if (can_move_to(cur))
                locations.push_back(cur);
        }
    }

    return locations;
}