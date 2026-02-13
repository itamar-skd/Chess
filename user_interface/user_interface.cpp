#include "user_interface.h"
#include "game_defines.h"
#include <ncurses.h>
#include <cmath>

UserInterface::UserInterface()
    : __manager()
{

}

void draw_tile(int x, int y, int color_pair)
{
    attron(COLOR_PAIR(color_pair));
    for (int dy = 0; dy < CHESS_BOARD_CELL_LENGTH; ++dy)
        for (int dx = 0; dx < CHESS_BOARD_CELL_WIDTH; ++dx)
            mvaddwstr(y * CHESS_BOARD_CELL_LENGTH + dy, x * CHESS_BOARD_CELL_WIDTH + dx, L"■");
    attroff(COLOR_PAIR(color_pair));
}

void draw_tile(int x, int y)
{
    if (x % 2 != y % 2)
        draw_tile(x, y, 0);
    else
        draw_tile(x, y, 1);
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
    for (int row = 0; row < CHESS_BOARD_SIZE; ++row)
    {
        for (int col = 0; col < CHESS_BOARD_SIZE; ++col)
        {
            draw_tile(col, row);
            this->__draw_piece(col, row);
        }
    }
}

void UserInterface::__run()
{
    MEVENT event;
    int ch;

    std::vector<Position> all_drawn_last;
    bool selected = false;

    while (this->__keep_alive && (ch = getch()) != 'q')
    {
        if (ch == KEY_MOUSE)
        {
            if (getmouse(&event) == OK)
            {
                if (event.bstate & BUTTON1_CLICKED)
                {
                    // mvprintw(0, 0, "left click detected at: y=%d, x=%d", event.y, event.x);
                    size_t x = (event.x - event.x % CHESS_BOARD_CELL_WIDTH) / CHESS_BOARD_CELL_WIDTH;
                    size_t y = (event.y - event.y % CHESS_BOARD_CELL_LENGTH) / CHESS_BOARD_CELL_LENGTH;
                    Position cur_pos(x, y);

                    if (x > CHESS_BOARD_SIZE || y > CHESS_BOARD_SIZE)
                        continue;

                    bool moved = false;
                    IChessPiece* cur_piece = this->__manager.get_piece(cur_pos);

                    if (selected && all_drawn_last.size() != 0)
                    {
                        if (this->__manager.get_piece(all_drawn_last[0])->can_move_to(cur_pos))
                        {
                            std::vector<Position> changed_cells = this->__manager.move(all_drawn_last[0], cur_pos);
                            for (Position& cell : changed_cells)
                            {
                                draw_tile(cell.x, cell.y);
                                this->__draw_piece(cell.x, cell.y);   
                            }

                            moved = true;
                        }
                        else
                            continue;
                    }

                    if (selected)
                    {
                        for (Position& pos : all_drawn_last)
                        {
                            /* redraw last tile */
                            draw_tile(pos.x, pos.y);
                            this->__draw_piece(pos.x, pos.y);
                        }

                        selected = false;
                    }

                    all_drawn_last.clear();

                    if (moved)
                        continue;

                    /* draw new tile */
                    draw_tile(x, y, 3);
                    this->__draw_piece(x, y);
                    all_drawn_last.push_back(cur_pos);
                    selected = true;

                    std::vector<Position> all_possible_moves = this->__manager.all_possible_moves(cur_pos);
                    for (Position& pos : all_possible_moves)
                    {
                        draw_tile(pos.x, pos.y, 2);
                        this->__draw_piece(pos.x, pos.y);
                        all_drawn_last.push_back(pos);
                    }

                    refresh();
                }
            }
        }
    }

    /* end the ncurses window */
    endwin();
}

void UserInterface::initialize()
{
    setlocale(LC_ALL, "");
    initscr(); /* initialize curses mode */
    use_default_colors();
    start_color();
    raw();
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

    /* initialize the thread */
    this->__keep_alive = true;
    this->__thrd = std::thread(&UserInterface::__run, this);
}

void UserInterface::stop()
{
    this->__keep_alive = false;
    if (this->__thrd.joinable())
        this->__thrd.join();

    endwin();
}