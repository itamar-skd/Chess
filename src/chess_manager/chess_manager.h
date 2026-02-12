#ifndef __CHESS_MANAGER_H__
#define __CHESS_MANAGER_H__

#include "piece_defines.h"
#include "game_defines.h"
#include <vector>
#include <memory>

class ChessManager final
{
    public:
        ChessManager();
        ~ChessManager() = default;

    public:
        bool move(Position from, Position to);
        inline IChessPiece* get_piece(Position pos) { return this->__pieces[pos.y][pos.x].get(); }

    private:
        std::unique_ptr<IChessPiece> __pieces[CHESS_BOARD_SIZE][CHESS_BOARD_SIZE];
};

#endif /* __CHESS_MANAGER_H__ */