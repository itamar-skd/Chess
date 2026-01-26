#include "bishop_piece.h"

BishopPiece::BishopPiece(bool is_enemy)
    : ChessPieceImpl(is_enemy)
{
}

bool BishopPiece::_can_move_to(uint32_t x, uint32_t y)
{
    return false; // TODO
}

bool BishopPiece::move(uint32_t x, uint32_t y)
{
    return false; // TODO
}