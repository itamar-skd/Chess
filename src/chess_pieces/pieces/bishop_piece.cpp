#include "bishop_piece.h"

BishopPiece::BishopPiece(Position pos)
    : ChessPieceImpl(E_ChessPiece::BISHOP, pos)
{
    
}

bool BishopPiece::can_move_to(Position pos)
{
    if (pos.x >= CHESS_BOARD_SIZE || pos.y >= CHESS_BOARD_SIZE)
        return false;

    /**
     * bishop moves diagonally. for linear functions with slope 1, by definition, for any two points (x1, y1) and (x2, y2), abs(x2 - x1) == abs(y2 - y1).
     */
    if (abs(pos.x - this->_pos.x) == abs(pos.y - this->_pos.y))
        return true;

    return false;
}

std::vector<Position> BishopPiece::all_possible_moves()
{
    std::vector<Position> locations;

    for (int x = 0; x < CHESS_BOARD_SIZE; x++)
    {
        Position first_diagonal(x, this->_pos.y + (this->_pos.x - x));
        Position second_diagonal(x, this->_pos.y - (this->_pos.x - x));

        if (this->can_move_to(first_diagonal))
            locations.push_back(first_diagonal);

        if (this->can_move_to(second_diagonal))
            locations.push_back(second_diagonal);
    }

    return locations;
}

const std::vector<std::string>& BishopPiece::drawing() const
{
    static const std::vector<std::string> art = {
        " o ",
        " (^) ",
        " -=H=- ",
        " ] [ ",
        " /___\\ "
    };
    return art;
}