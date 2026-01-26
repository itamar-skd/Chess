#include "pawn_piece.h"

PawnPiece::PawnPiece(bool is_enemy)
    : ChessPieceImpl(is_enemy)
{
}

bool PawnPiece::_can_move_to(uint32_t x, uint32_t y)
{
    return false; // TODO
}

bool PawnPiece::move(uint32_t x, uint32_t y)
{
    return false; // TODO
}