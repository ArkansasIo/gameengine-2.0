cmake_minimum_required(VERSION 3.10)
project(LunaLite)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Source files
set(SOURCES
    Point.cpp
    Rectangle.cpp
    Bitmap.cpp
    Graphics.cpp
    Input.cpp
    CacheEntry.cpp
    CacheMap.cpp
    JsonEx.cpp
)

# Header files
set(HEADERS
    Point.h
    Rectangle.h
    Bitmap.h
    Graphics.h
    Input.h
    CacheEntry.h
    CacheMap.h
    JsonEx.h
)

# Create library
add_library(lunalite STATIC ${SOURCES} ${HEADERS})

# Include directory
target_include_directories(lunalite PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
