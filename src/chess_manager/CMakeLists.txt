SET(CHESS_MANAGER_SOURCES
    chess_manager.cpp
)

set(CHESS_MANAGER_HEADERS
    chess_manager.h
)

LIST(SORT CHESS_MANAGER_SOURCES)

add_library(chess_manager ${CHESS_MANAGER_SOURCES} ${CHESS_MANAGER_HEADERS})
target_include_directories(chess_manager PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(chess_manager
    PRIVATE
        core
        chess_pieces
)