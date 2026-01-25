#include "chess_manager.h"

ChessManager::ChessManager()
{
    for (size_t y = 0; y < BOARD_SIZE; y++)
    {
        for (size_t x = 0; x < BOARD_SIZE; x++)
        {
            this->__pieces[y][x] = nullptr;
        }
    }

    // White pieces
    this->__pieces[0][0] = std::make_unique<RookPiece>(false);
    this->__pieces[0][1] = std::make_unique<KnightPiece>(false);
    this->__pieces[0][2] = std::make_unique<BishopPiece>(false);
    this->__pieces[0][3] = std::make_unique<QueenPiece>(false);
    this->__pieces[0][4] = std::make_unique<KingPiece>(false);
    this->__pieces[0][5] = std::make_unique<BishopPiece>(false);
    this->__pieces[0][6] = std::make_unique<KnightPiece>(false);
    this->__pieces[0][7] = std::make_unique<RookPiece>(false);

    for (int x = 0; x < BOARD_SIZE; ++x) {
        this->__pieces[1][x] = std::make_unique<PawnPiece>(false);
    }

    // Black pieces
    this->__pieces[7][0] = std::make_unique<RookPiece>(true);
    this->__pieces[7][1] = std::make_unique<KnightPiece>(true);
    this->__pieces[7][2] = std::make_unique<BishopPiece>(true);
    this->__pieces[7][3] = std::make_unique<QueenPiece>(true);
    this->__pieces[7][4] = std::make_unique<KingPiece>(true);
    this->__pieces[7][5] = std::make_unique<BishopPiece>(true);
    this->__pieces[7][6] = std::make_unique<KnightPiece>(true);
    this->__pieces[7][7] = std::make_unique<RookPiece>(true);

    for (int x = 0; x < BOARD_SIZE; ++x) {
        this->__pieces[6][x] = std::make_unique<PawnPiece>(true);
    }
}