cmake_minimum_required (VERSION 3.8)

set(SOURCES
    main.cpp
    main.h
    TextWord.cpp
    TextWord.h
)

file(GLOB INPUT_DATA ${PROJECT_SOURCE_DIR}/*.txt)
file(COPY ${INPUT_DATA} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_executable(${PROJECT_NAME} ${SOURCES})
