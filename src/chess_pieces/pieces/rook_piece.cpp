#include "rook_piece.h"

RookPiece::RookPiece(Position pos)
    : ChessPieceImpl(E_ChessPiece::ROOK, pos)
{
    
}

bool RookPiece::can_move_to(Position pos)
{
    return false; // TODO
}

std::vector<Position> RookPiece::all_possible_moves()
{
    std::vector<Position> locations;

    // TODO

    return locations;
}

const char* RookPiece::drawing() const
{
    return ""; // TODO!
}