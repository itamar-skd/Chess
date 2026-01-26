#include "king_piece.h"

KingPiece::KingPiece(bool is_enemy)
    : ChessPieceImpl(is_enemy)
{
}

bool KingPiece::_can_move_to(uint32_t x, uint32_t y)
{
    return false; // TODO
}

bool KingPiece::move(uint32_t x, uint32_t y)
{
    return false; // TODO
}