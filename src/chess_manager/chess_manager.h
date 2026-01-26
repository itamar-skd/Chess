#ifndef __CHESS_MANAGER_H__
#define __CHESS_MANAGER_H__

#include "piece_defines.h"
#include "game_settings.h"
#include <vector>
#include <memory>

class ChessManager final
{
    public:
        ChessManager();
        ~ChessManager() = default;

    private:
        std::unique_ptr<IChessPiece> __pieces[CHESS_BOARD_SIZE][CHESS_BOARD_SIZE];
};

#endif /* __CHESS_MANAGER_H__ */