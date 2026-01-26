#include "chess_manager.h"
#include "position.h"

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
    this->__pieces[0][0] = std::make_unique<RookPiece>  (Position(0, 0), false);
    this->__pieces[0][1] = std::make_unique<KnightPiece>(Position(1, 0), false);
    this->__pieces[0][2] = std::make_unique<BishopPiece>(Position(2, 0), false);
    this->__pieces[0][3] = std::make_unique<QueenPiece> (Position(3, 0), false);
    this->__pieces[0][4] = std::make_unique<KingPiece>  (Position(4, 0), false);
    this->__pieces[0][5] = std::make_unique<BishopPiece>(Position(5, 0), false);
    this->__pieces[0][6] = std::make_unique<KnightPiece>(Position(6, 0), false);
    this->__pieces[0][7] = std::make_unique<RookPiece>  (Position(7, 0), false);

    for (int x = 0; x < CHESS_BOARD_SIZE; ++x) {
        this->__pieces[1][x] = std::make_unique<PawnPiece>(Position(x, 1), false);
    }

    // Black pieces
    this->__pieces[7][0] = std::make_unique<RookPiece>  (Position(0, 7), true);
    this->__pieces[7][1] = std::make_unique<KnightPiece>(Position(1, 7), true);
    this->__pieces[7][2] = std::make_unique<BishopPiece>(Position(2, 7), true);
    this->__pieces[7][3] = std::make_unique<QueenPiece> (Position(3, 7), true);
    this->__pieces[7][4] = std::make_unique<KingPiece>  (Position(4, 7), true);
    this->__pieces[7][5] = std::make_unique<BishopPiece>(Position(5, 7), true);
    this->__pieces[7][6] = std::make_unique<KnightPiece>(Position(6, 7), true);
    this->__pieces[7][7] = std::make_unique<RookPiece>  (Position(7, 7), true);

    for (int x = 0; x < CHESS_BOARD_SIZE; ++x) {
        this->__pieces[6][x] = std::make_unique<PawnPiece>(Position(x, 6), true);
    }
}