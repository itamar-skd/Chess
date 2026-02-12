#include "bishop_piece.h"

BishopPiece::BishopPiece(Position pos)
    : ChessPieceImpl(E_ChessPiece::BISHOP, pos)
{
    
}

bool BishopPiece::can_move_to(Position pos)
{
    return false; // TODO
}

std::vector<Position> BishopPiece::all_possible_moves()
{
    std::vector<Position> locations;

    // TODO

    return locations;
}

const char* BishopPiece::drawing() const
{
    return ""; // TODO!
}