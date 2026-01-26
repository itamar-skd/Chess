#include "knight_piece.h"

KnightPiece::KnightPiece(bool is_enemy)
    : ChessPieceImpl(is_enemy)
{
}

bool KnightPiece::_can_move_to(uint32_t x, uint32_t y)
{
    return false; // TODO
}

bool KnightPiece::move(uint32_t x, uint32_t y)
{
    return false; // TODO
}