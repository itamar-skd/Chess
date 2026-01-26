#include "pawn_piece.h"
#include "game_settings.h"
#include <cmath>

PawnPiece::PawnPiece(uint32_t x, uint32_t y, bool is_enemy)
    : ChessPieceImpl(x, y, is_enemy)
    , __is_first(true)
{
    
}

bool PawnPiece::can_move_to(uint32_t x, uint32_t y)
{
    if (x >= CHESS_BOARD_SIZE || y >= CHESS_BOARD_SIZE)
        return false;

    // A pawn moves only forwards when not trying to capture OR diagonally when capturing
    if (this->_x != x)
    {
        if ((abs(this->_x - x) == 1) && y - this->_y == 1)
            return true;

        return false;
    }

    if (y - this->_y == 1)
        return true;

    if (y - this->_y == 2 && this->__is_first)
        return true;

    return false;
}

bool PawnPiece::move(uint32_t x, uint32_t y)
{
    if (!this->can_move_to(x, y))
        return false;

    this->_x = x;
    this->_y = y;
    this->__is_first = false;
    return true;
}