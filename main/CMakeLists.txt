SET(MAIN_SOURCES
    main.cpp
)

LIST(SORT MAIN_SOURCES)

add_executable(chess main.cpp)

target_link_libraries(chess
    PRIVATE    
        chess_manager
)
target_include_directories(chess PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})