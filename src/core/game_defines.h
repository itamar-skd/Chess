#ifndef __GAME_SETTINGS_H__
#define __GAME_SETTINGS_H__

#define CHESS_BOARD_SIZE 8
#define CHESS_BOARD_CELL_LENGTH 8
#define CHESS_BOARD_CELL_WIDTH 16

typedef enum {
    PAWN,
    ROOK,
    BISHOP,
    KNIGHT,
    QUEEN,
    KING
} E_ChessPiece;

#endif /* __GAME_SETTINGS_H__ */