#include "chess_manager.h"

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
    this->__pieces[0][0] = std::make_unique<RookPiece>(0, 0, false);
    this->__pieces[0][1] = std::make_unique<KnightPiece>(1, 0, false);
    this->__pieces[0][2] = std::make_unique<BishopPiece>(2, 0, false);
    this->__pieces[0][3] = std::make_unique<QueenPiece>(3, 0, false);
    this->__pieces[0][4] = std::make_unique<KingPiece>(4, 0, false);
    this->__pieces[0][5] = std::make_unique<BishopPiece>(5, 0, false);
    this->__pieces[0][6] = std::make_unique<KnightPiece>(6, 0, false);
    this->__pieces[0][7] = std::make_unique<RookPiece>(7, 0, false);

    for (int x = 0; x < CHESS_BOARD_SIZE; ++x) {
        this->__pieces[1][x] = std::make_unique<PawnPiece>(x, 1, false);
    }

    // Black pieces
    this->__pieces[7][0] = std::make_unique<RookPiece>(0, 7, true);
    this->__pieces[7][1] = std::make_unique<KnightPiece>(1, 7, true);
    this->__pieces[7][2] = std::make_unique<BishopPiece>(2, 7, true);
    this->__pieces[7][3] = std::make_unique<QueenPiece>(3, 7, true);
    this->__pieces[7][4] = std::make_unique<KingPiece>(4, 7, true);
    this->__pieces[7][5] = std::make_unique<BishopPiece>(5, 7, true);
    this->__pieces[7][6] = std::make_unique<KnightPiece>(6, 7, true);
    this->__pieces[7][7] = std::make_unique<RookPiece>(7, 7, true);

    for (int x = 0; x < CHESS_BOARD_SIZE; ++x) {
        this->__pieces[6][x] = std::make_unique<PawnPiece>(x, 6, true);
    }
}