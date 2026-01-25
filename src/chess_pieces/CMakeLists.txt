SET(CHESS_PIECES_SOURCES
    pieces/king_piece.cpp
    pieces/queen_piece.cpp
    pieces/pawn_piece.cpp
    pieces/rook_piece.cpp
    pieces/knight_piece.cpp
    pieces/bishop_piece.cpp
)

set(CHESS_PIECES_HEADERS
    pieces/chess_piece.h
    pieces/king_piece.h
    pieces/queen_piece.h
    pieces/pawn_piece.h
    pieces/rook_piece.h
    pieces/knight_piece.h
    pieces/bishop_piece.h
    piece_defines.h
)

LIST(SORT CHESS_PIECES_SOURCES)
LIST(SORT CHESS_PIECES_HEADERS)

add_library(chess_pieces ${CHESS_PIECES_SOURCES} ${CHESS_PIECES_HEADERS})
target_include_directories(chess_pieces PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})