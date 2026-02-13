#include "user_interface.h"
#include "game_defines.h"
#include <ncurses.h>
#include <cmath>

UserInterface::UserInterface()
    : __manager()
{

}

void draw_tile(int y, int x, int color_pair)
{
    attron(COLOR_PAIR(color_pair));
    for (int dy = 0; dy < CHESS_BOARD_CELL_LENGTH; ++dy)
        for (int dx = 0; dx < CHESS_BOARD_CELL_WIDTH; ++dx)
            mvaddwstr(y * 8 + dy, x * CHESS_BOARD_CELL_WIDTH+ dx, L"■");
    attroff(COLOR_PAIR(color_pair));
    refresh();
}

void UserInterface::__draw_piece(size_t x, size_t y)
{
    IChessPiece* piece = this->__manager.get_piece(Position(x, y));
    if (piece != nullptr)
    {
        const std::vector<std::string>& art = piece->drawing();
        size_t num_rows = art.size();

        if (piece->is_enemy())
            attron(COLOR_PAIR(2));

        for (size_t i = 0; i < num_rows; i++)
        {
            size_t num_cols_to_pad = (CHESS_BOARD_CELL_WIDTH - art[i].length()) / 2;
            size_t start_y = y * CHESS_BOARD_CELL_LENGTH + 7 - (num_rows - i);
            size_t start_x = x * CHESS_BOARD_CELL_WIDTH + num_cols_to_pad;
            mvprintw(start_y, start_x, "%s", art[i].c_str());
        }

        attroff(COLOR_PAIR(2));
    }
}

void UserInterface::__draw_board()
{
    for (int row = 0; row < 8; ++row)
    {
        for (int col = 0; col < 8; ++col)
        {
            if (row % 2 != col % 2)
                draw_tile(row, col, 0);
            else
                draw_tile(row, col, 1);

            this->__draw_piece(col, row);
            refresh();
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