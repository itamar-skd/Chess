#ifndef __USER_INTERFACE_H__
#define __USER_INTERFACE_H__

#include "chess_manager.h"
#include <ncurses.h>
#include <thread>

class UserInterface final
{
    public:
        UserInterface();
        ~UserInterface() = default;

    private:
        void __draw_piece(size_t x, size_t y);
        void __draw_board();

    private:
        void __run();

    public:
        void initialize();
        void stop();
        inline void join() { this->__thrd.join(); }
    
    private:
        /* thread */
            bool __keep_alive;
            std::thread __thrd;
        
        /* manager */
        ChessManager __manager;
};

#endif /* __USER_INTERFACE_H__ */