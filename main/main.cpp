#include <iostream>
#include <unistd.h>
#include "user_interface.h"

int main(int argc, char** argv)
{
    // ChessManager manager;
    // Position pawn_first(0, 1);
    // Position pawn_end(1, 2);
    // Position queen_first(3, 7);
 
    // bool a = manager.move(queen_first, pawn_end);
    // bool b = manager.move(pawn_first, pawn_end);
    // std::cout << (a ? "ya" : "na") << "\n";
    // std::cout << (b  ? "ya" : "na") << "\n";

    UserInterface interface;
    interface.initialize();
    attron(COLOR_PAIR(1));
    // addch(ACS_BLOCK);
    addwstr(L"■");
    attroff(COLOR_PAIR(1));
    refresh();
    sleep(10);
    interface.stop();
    return 0;
}