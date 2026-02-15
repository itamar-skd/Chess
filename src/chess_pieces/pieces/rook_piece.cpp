#include "rook_piece.h"

RookPiece::RookPiece(Position pos)
    : ChessPieceImpl(E_ChessPiece::ROOK, pos)
{
    
}

bool RookPiece::can_move_to(Position pos)
{
    if (pos.x >= CHESS_BOARD_SIZE || pos.y >= CHESS_BOARD_SIZE)
        return false;

    /**
     * the rook can move as many spaces as it wants horizontally/vertically.
     * therefore, any spot that it can move to must either be:
     *  1. on the same horizontal line as the rook (i.e. pos.x == this->_pos.x && pos.y != this->_pos.y)
     *  2. on the same vertical line as the rook (i.e. pos.x != this->_pos.x && pos.y == this->_pos.y)
     */
    if ((pos.x == this->_pos.x) == (pos.y == this->_pos.y))
        return false;

    return true;
}

std::vector<Position> RookPiece::all_possible_moves()
{
    std::vector<Position> locations;

    for (size_t x = 0; x < CHESS_BOARD_SIZE; x++)
    {
        Position pos(x, this->_pos.y);
        if (this->can_move_to(pos))
            locations.push_back(pos);
    }

    for (size_t y = 0; y < CHESS_BOARD_SIZE; y++)
    {
        Position pos(this->_pos.x, y);
        if (this->can_move_to(pos))
            locations.push_back(pos);
    }

    return locations;
}

const std::vector<std::string>& RookPiece::drawing() const
{
    static const std::vector<std::string> art = {
        " [UU] ",
        " || ",
        " {} ",
        " {__} "
    };

    return art;
}