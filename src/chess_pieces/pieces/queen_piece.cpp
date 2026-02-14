#include "queen_piece.h"

QueenPiece::QueenPiece(Position pos)
    : ChessPieceImpl(E_ChessPiece::QUEEN, pos)
{
    
}

bool QueenPiece::can_move_to(Position pos)
{
    if (pos.x >= CHESS_BOARD_SIZE || pos.y >= CHESS_BOARD_SIZE)
        return false;

    if (pos.x == this->_pos.x || pos.y == this->_pos.y)
        return true;

    if (abs(pos.x - this->_pos.x) == abs(pos.y - this->_pos.y))
        return true;

    return false;
}

std::vector<Position> QueenPiece::all_possible_moves()
{
    std::vector<Position> locations;

    for (size_t i = 0; i < CHESS_BOARD_SIZE; i++)
    {
        if (i == this->_pos.x)
            continue;

        locations.push_back(Position(i, this->_pos.y));
        locations.push_back(Position(i, this->_pos.y + abs(this->_pos.x - i)));
        locations.push_back(Position(i, this->_pos.y - abs(this->_pos.x - i)));
    }

    for (size_t i = 0; i < CHESS_BOARD_SIZE; i++)
        if (i != this->_pos.y)
            locations.push_back(Position(this->_pos.x, i));

    for (std::vector<Position>::iterator it = locations.begin(); it != locations.end();)
    {
        if (!this->can_move_to(*it))
        {
            locations.erase(it);
            continue;
        }

        it++;
    }

    return locations;
}

const std::vector<std::string>& QueenPiece::drawing() const
{
    static const std::vector<std::string> art = {
        " _._ ",
        " ( ) ",
        " / \\ ",
        " | | ",
        " { } ",
        " {___} "
    };

    return art;
}