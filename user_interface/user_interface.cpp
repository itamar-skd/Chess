#include "user_interface.h"
#include "game_defines.h"
#include <ncurses.h>

UserInterface::UserInterface()
    : __manager()
{

}

void draw_tile(int y, int x, int color_pair)
{
    attron(COLOR_PAIR(color_pair));
    for (int dy = 0; dy < 8; ++dy)
        for (int dx = 0; dx < 16; ++dx)
            mvaddwstr(y * 8 + dy, x * 16 + dx, L"■");
    attroff(COLOR_PAIR(color_pair));
    refresh();
}

void UserInterface::__draw_board()
{
    for (int row = 0; row < 8; ++row)
    {
        for (int col = 0; col < 8; ++col)
        {
            IChessPiece* piece = this->__manager.get_piece(Position(col, row));
            if (piece == nullptr)
            {
                if (row % 2 != col % 2)
                    draw_tile(row, col, 0);
                else
                    draw_tile(row, col, 1);
            }
            else
            {
                // TODO: Draw piece
            }
        }
    }
}

void UserInterface::initialize()
{
    setlocale(LC_ALL, "");
    initscr(); /* initialize curses mode */
    use_default_colors();
    start_color();
    keypad(stdscr, TRUE); // Enable special keys (arrows, etc.)
    mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, NULL);
    noecho();
    cbreak();
    resize_term(0, 0);
    curs_set(0);
    init_pair(0, COLOR_BLACK, -1);
    init_pair(1, COLOR_WHITE, -1);
    init_pair(2, COLOR_RED, -1);
    init_pair(3, COLOR_BLUE, -1);
    init_pair(4, COLOR_GREEN, -1);
    this->__draw_board();
    refresh();
}

void UserInterface::stop()
{
    endwin();
}