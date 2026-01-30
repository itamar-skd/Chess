#include "chess_manager.h"
#include "position.h"
#include <cmath>

ChessManager::ChessManager()
{
    for (size_t y = 0; y < CHESS_BOARD_SIZE; y++)
    {
        for (size_t x = 0; x < CHESS_BOARD_SIZE; x++)
        {
            this->__pieces[y][x] = nullptr;
        }
    }

    // White pieces
    this->__pieces[0][0] = std::make_unique<RookPiece>  (Position(0, 0));
    this->__pieces[0][1] = std::make_unique<KnightPiece>(Position(1, 0));
    this->__pieces[0][2] = std::make_unique<BishopPiece>(Position(2, 0));
    this->__pieces[0][3] = std::make_unique<QueenPiece> (Position(3, 0));
    this->__pieces[0][4] = std::make_unique<KingPiece>  (Position(4, 0));
    this->__pieces[0][5] = std::make_unique<BishopPiece>(Position(5, 0));
    this->__pieces[0][6] = std::make_unique<KnightPiece>(Position(6, 0));
    this->__pieces[0][7] = std::make_unique<RookPiece>  (Position(7, 0));

    for (int x = 0; x < CHESS_BOARD_SIZE; ++x) {
        this->__pieces[1][x] = std::make_unique<PawnPiece>(Position(x, 1));
    }

    // Black pieces
    this->__pieces[7][0] = std::make_unique<RookPiece>  (Position(0, 7));
    this->__pieces[7][1] = std::make_unique<KnightPiece>(Position(1, 7));
    this->__pieces[7][2] = std::make_unique<BishopPiece>(Position(2, 7));
    this->__pieces[7][3] = std::make_unique<QueenPiece> (Position(3, 7));
    this->__pieces[7][4] = std::make_unique<KingPiece>  (Position(4, 7));
    this->__pieces[7][5] = std::make_unique<BishopPiece>(Position(5, 7));
    this->__pieces[7][6] = std::make_unique<KnightPiece>(Position(6, 7));
    this->__pieces[7][7] = std::make_unique<RookPiece>  (Position(7, 7));

    for (int x = 0; x < CHESS_BOARD_SIZE; ++x) {
        this->__pieces[6][x] = std::make_unique<PawnPiece>(Position(x, 6));
    }
}

bool ChessManager::move(Position from, Position to)
{
    if (from.y >= CHESS_BOARD_SIZE || from.x >= CHESS_BOARD_SIZE || to.x >= CHESS_BOARD_SIZE || to.y >= CHESS_BOARD_SIZE)
        return false;

    IChessPiece* piece = this->__pieces[from.y][from.x].get();
    if (piece == nullptr)
        return false;

    if (!piece->can_move_to(to))
        return false;

    bool try_capturing = true;
    if (piece->kind() == E_ChessPiece::PAWN)
    {
        // trying to capture
        if (to.x != from.x)
        {
            if (this->__pieces[to.y][to.x] == nullptr)
                return false;
        }
        else
            try_capturing = false;
    }
    else if (piece->kind() == E_ChessPiece::KING)
    {
        // Attempting to castle
        if (abs(to.x - from.x) == 2 && to.y == from.y)
        {
            if (piece->has_moved())
                return false;

            int distance_to_rook = (to.x > from.x) ? (CHESS_BOARD_SIZE - 1) - from.x : -1 * (from.x - 1);
            IChessPiece* rook = this->__pieces[from.y][from.x + distance_to_rook].get();

            if (rook->kind() != E_ChessPiece::ROOK)
                return false;

            if (rook->has_moved())
                return false;

            // Check that all spots between rook and king are empty
            int dx = distance_to_rook > 0 ? 1 : -1;
            while (dx != distance_to_rook)
            {
                if (this->__pieces[from.y][from.x + dx].get() != nullptr)
                    return false;

                dx += (distance_to_rook > 0) ? 1 : -1; 
            }

            Position rook_pos(from.x + 1, from.y);
            rook->move(rook_pos);
            this->__pieces[rook_pos.y][rook_pos.x] = std::move(this->__pieces[from.y][from.x + distance_to_rook]);
        }
    }

    if (try_capturing)
    {
        // Check for capturing. If both pieces are on the same team, then return false. Otherwise, capture the piece.
        IChessPiece* possible_capture = this->__pieces[to.y][to.x].get();
        if (possible_capture != nullptr && possible_capture->is_enemy() == piece->is_enemy())
            return false;
    }

    piece->move(to);
    this->__pieces[to.y][to.x] = std::move(this->__pieces[from.y][from.x]);

    return true;
}