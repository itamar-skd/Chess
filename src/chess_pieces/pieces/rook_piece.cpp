#include "rook_piece.h"

RookPiece::RookPiece(bool is_enemy)
    : ChessPieceImpl(is_enemy)
{
}

bool RookPiece::_can_move_to(uint32_t x, uint32_t y)
{
    return false; // TODO
}

bool RookPiece::move(uint32_t x, uint32_t y)
{
    return false; // TODO
}