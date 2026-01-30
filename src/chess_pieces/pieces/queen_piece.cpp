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