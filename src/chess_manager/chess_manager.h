#ifndef __CHESS_MANAGER_H__
#define __CHESS_MANAGER_H__

#include "piece_defines.h"
#include <vector>
#include <memory>

#define BOARD_SIZE 8

class ChessManager final
{
    public:
        ChessManager();
        ~ChessManager() = default;

    private:
        std::unique_ptr<IChessPiece> __pieces[BOARD_SIZE][BOARD_SIZE];
};

#endif /* __CHESS_MANAGER_H__ */