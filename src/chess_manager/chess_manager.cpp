#include "chess_manager.h"
#include "position.h"
#include <cmath>
#include <algorithm>

ChessManager::ChessManager()
{
    for (size_t y = 0; y < CHESS_BOARD_SIZE; y++)
    {
        for (size_t x = 0; x < CHESS_BOARD_SIZE; x++)
        {
            this->__pieces[y][x] = nullptr;
        }
    }

    // White pieces
    this->__pieces[0][0] = std::make_unique<RookPiece>  (Position(0, 0));
    this->__pieces[0][1] = std::make_unique<KnightPiece>(Position(1, 0));
    this->__pieces[0][2] = std::make_unique<BishopPiece>(Position(2, 0));
    this->__pieces[0][3] = std::make_unique<QueenPiece> (Position(3, 0));
    this->__pieces[0][4] = std::make_unique<KingPiece>  (Position(4, 0));
    this->__pieces[0][5] = std::make_unique<BishopPiece>(Position(5, 0));
    this->__pieces[0][6] = std::make_unique<KnightPiece>(Position(6, 0));
    this->__pieces[0][7] = std::make_unique<RookPiece>  (Position(7, 0));

    for (int x = 0; x < CHESS_BOARD_SIZE; ++x) {
        this->__pieces[1][x] = std::make_unique<PawnPiece>(Position(x, 1));
    }

    // Black pieces
    this->__pieces[7][0] = std::make_unique<RookPiece>  (Position(0, 7));
    this->__pieces[7][1] = std::make_unique<KnightPiece>(Position(1, 7));
    this->__pieces[7][2] = std::make_unique<BishopPiece>(Position(2, 7));
    this->__pieces[7][3] = std::make_unique<QueenPiece> (Position(3, 7));
    this->__pieces[7][4] = std::make_unique<KingPiece>  (Position(4, 7));
    // this->__pieces[7][5] = std::make_unique<BishopPiece>(Position(5, 7));
    // this->__pieces[7][6] = std::make_unique<KnightPiece>(Position(6, 7));
    this->__pieces[7][7] = std::make_unique<RookPiece>  (Position(7, 7));

    for (int x = 0; x < CHESS_BOARD_SIZE; ++x) {
        this->__pieces[6][x] = std::make_unique<PawnPiece>(Position(x, 6));
    }
}

std::vector<Position> ChessManager::move(Position from, Position to)
{
    std::vector<Position> changed_cells;
    if (from.y >= CHESS_BOARD_SIZE || from.x >= CHESS_BOARD_SIZE || to.x >= CHESS_BOARD_SIZE || to.y >= CHESS_BOARD_SIZE)
        return changed_cells;

    IChessPiece* piece = this->__pieces[from.y][from.x].get();
    if (piece == nullptr)
        return changed_cells;

    if (!piece->can_move_to(to))
        return changed_cells;

    std::vector<Position> all_possible_moves = this->all_possible_moves(from);
    if (all_possible_moves.size() == 0)
        return changed_cells;

    // all_possible_moves returns all of the moves a piece can make. if `to` isn't in that list, then it's not a valid move.
    if (std::find(all_possible_moves.begin(), all_possible_moves.end(), to) == all_possible_moves.end())
        return changed_cells;

    // piece-specific checks
    if (piece->kind() == E_ChessPiece::KING)
    {
        // Castling
        if (abs(from.x - to.x) >= 2)
        {
            bool direction = from.x > to.x; // true = left, false = right
            int distance_to_rook = direction ? -4 : 3;
            IChessPiece* rook = this->__pieces[from.y][from.x + distance_to_rook].get();
            if (rook == nullptr)
                return changed_cells; // THIS SHOULD NEVER BE REACHABLE!

            Position rook_pos(from.x + (direction ? -1 : 1), from.y);
            rook->move(rook_pos);
            this->__pieces[rook_pos.y][rook_pos.x] = std::move(this->__pieces[from.y][from.x + distance_to_rook]);
            changed_cells.push_back(Position(from.x + distance_to_rook, from.y));
            changed_cells.push_back(rook_pos);
        }
    }

    // Check for capturing. If both pieces are on the same team, then return false. Otherwise, capture the piece.
    IChessPiece* possible_capture = this->__pieces[to.y][to.x].get();
    if (possible_capture != nullptr && possible_capture->is_enemy() == piece->is_enemy())
        return changed_cells;

    piece->move(to);
    this->__pieces[to.y][to.x] = std::move(this->__pieces[from.y][from.x]);
    changed_cells.push_back(from);
    changed_cells.push_back(to);

    return changed_cells;
}

std::vector<Position> ChessManager::all_possible_moves(Position pos) const
{
    std::vector<Position> moves;
    if (pos.x > CHESS_BOARD_SIZE || pos.y >= CHESS_BOARD_SIZE)
        return moves;

    IChessPiece* piece = this->__pieces[pos.y][pos.x].get();
    moves = piece->all_possible_moves();

    for (std::vector<Position>::iterator it = moves.begin(); it != moves.end();)
    {
        IChessPiece* move_piece = this->__pieces[it->y][it->x].get();
        if (piece->kind() == E_ChessPiece::PAWN)
        {
            if (it->x == pos.x)
            {
                if (move_piece != nullptr)
                {
                    moves.erase(it);
                    continue;
                }
            }
            // capturing moves
            else if (abs(it->x - pos.x) == 1)
            {
                if ((move_piece == nullptr) || (move_piece->is_enemy() == piece->is_enemy()))
                {
                    moves.erase(it);
                    continue;
                }
            }
        }
        else if (piece->kind() == E_ChessPiece::KING)
        {
            if (abs(it->x - pos.x) == 1 || abs(it->y - pos.y) == 1)
            {
                IChessPiece* to_piece = this->__pieces[it->y][it->x].get();
                if (to_piece != nullptr && to_piece->is_enemy() == piece->is_enemy())
                {
                    moves.erase(it);
                    continue;
                }
            }
            // Castling
            else if (abs(it->x - pos.x) == 2 && it->y == pos.y)
            {
                if (piece->has_moved())
                {
                    moves.erase(it);
                    continue;
                }

                int distance_to_rook = (it->x > pos.x) ? (CHESS_BOARD_SIZE - 1) - pos.x : -1 * (pos.x - 1);
                IChessPiece* rook = this->__pieces[pos.y][pos.x + distance_to_rook].get();

                if (rook->kind() != E_ChessPiece::ROOK)
                {
                    moves.erase(it);
                    continue;
                }

                if (rook->has_moved())
                {
                    moves.erase(it);
                    continue;
                }

                // Check that all spots between rook and king are empty
                int dx = distance_to_rook > 0 ? 1 : -1;
                bool can_move = true;
                while (dx != distance_to_rook)
                {
                    if (this->__pieces[pos.y][pos.x + dx].get() != nullptr)
                        can_move = false;

                    dx += (distance_to_rook > 0) ? 1 : -1; 
                }

                if (!can_move)
                {
                    moves.erase(it);
                    continue;
                }
            }
        }

        it++;
    }

    return moves;
}