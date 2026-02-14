#include "knight_piece.h"
#include <cmath>
#include <ncurses.h>

KnightPiece::KnightPiece(Position pos)
    : ChessPieceImpl(E_ChessPiece::KNIGHT, pos)
{

}

bool KnightPiece::can_move_to(Position pos)
{
    if (pos.x >= CHESS_BOARD_SIZE || pos.y >= CHESS_BOARD_SIZE)
        return false;

    if (sqrt(pow(pos.x - this->_pos.x, 2) + pow(pos.y - this->_pos.y, 2)) == sqrt(5))
        return true;

    return false;
}

std::vector<Position> KnightPiece::all_possible_moves()
{
    std::vector<Position> locations;

    for (int x = this->_pos.x - 2; x <= this->_pos.x + 2; x++)
    {
        for (int y = this->_pos.y - 2; y <= this->_pos.y + 2; y++)
        {
            if (x < 0 || y < 0)
                continue;

            Position pos(x, y);
            if (this->can_move_to(pos))
                locations.push_back(pos);
        }
    }

    return locations;
}

const std::vector<std::string>& KnightPiece::drawing() const
{
    static const std::vector<std::string> art = {
        "  T\\ ",
        "  |\\) ",
        "  {} ",
        " {__} "
    };

    return art;
}