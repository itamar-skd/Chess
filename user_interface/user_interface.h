#ifndef __USER_INTERFACE_H__
#define __USER_INTERFACE_H__

#include "chess_manager.h"
#include <ncurses.h>

class UserInterface final
{
    public:
        UserInterface();
        ~UserInterface() = default;

    private:
        void __draw_piece(size_t x, size_t y);
        void __draw_board();

    public:
        void initialize();
        void stop();
    
    private:
        ChessManager __manager;
};

#endif /* __USER_INTERFACE_H__ */