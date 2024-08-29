cmake_minimum_required(VERSION 3.5)

project(main)

add_library(
    MVC_Manage_Folder
    ${CMAKE_CURRENT_SOURCE_DIR}/src/MVC_Manage_Folder.cpp
)

add_executable(
    main
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/header/MVC_Manage_Folder.hpp
)

target_link_libraries(
    main
    MVC_Manage_Folder
    stdc++fs
    SDL2_mixer
)