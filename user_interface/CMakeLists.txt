SET(USER_INTERFACE_SOURCES
    user_interface.cpp
)

set(USER_INTERFACE_HEADERS
    user_interface.h
)

LIST(SORT USER_INTERFACE_SOURCES)

add_library(user_interface ${USER_INTERFACE_SOURCES} ${USER_INTERFACE_HEADERS})
target_include_directories(user_interface PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

target_link_libraries(user_interface
    PUBLIC
        core
        chess_manager
        ncursesw
)