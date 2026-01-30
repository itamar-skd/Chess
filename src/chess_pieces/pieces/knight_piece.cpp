#include "knight_piece.h"

KnightPiece::KnightPiece(Position pos)
    : ChessPieceImpl(E_ChessPiece::KNIGHT, pos)
{

}

bool KnightPiece::can_move_to(Position pos)
{
    return false; // TODO
}

std::vector<Position> KnightPiece::all_possible_moves()
{
    std::vector<Position> locations;

    // TODO

    return locations;
}