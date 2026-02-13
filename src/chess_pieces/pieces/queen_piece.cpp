#include "queen_piece.h"

QueenPiece::QueenPiece(Position pos)
    : ChessPieceImpl(E_ChessPiece::QUEEN, pos)
{
    
}

bool QueenPiece::can_move_to(Position pos)
{
    return true; // TODO
}

std::vector<Position> QueenPiece::all_possible_moves()
{
    std::vector<Position> locations;

    // TODO

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