#include "queen_piece.h"

QueenPiece::QueenPiece(bool is_enemy)
    : ChessPieceImpl(is_enemy)
{
}

bool QueenPiece::_can_move_to(uint32_t x, uint32_t y)
{
    return false; // TODO
}

bool QueenPiece::move(uint32_t x, uint32_t y)
{
    return false; // TODO
}