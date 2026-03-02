cmake_minimum_required(VERSION 3.16)
project(LunaLite)

# C++ Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Make sure our current directory is first in include paths
include_directories(BEFORE ${CMAKE_CURRENT_SOURCE_DIR})

# Platform-specific flags
if(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4 /EHsc")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -fPIC")
endif()

# Optional Qt Configuration
option(ENABLE_QT "Use Qt5 for GUI components" OFF)

if(ENABLE_QT)
    set(CMAKE_AUTOMOC ON)
    set(CMAKE_AUTORCC ON)
    set(CMAKE_AUTOUIC ON)
    
    find_package(Qt5 COMPONENTS 
        Core 
        Gui 
        Widgets 
        Multimedia 
        Network 
        REQUIRED
    )
    
    message(STATUS "Qt5 Support: ENABLED")
else()
    message(STATUS "Qt5 Support: DISABLED")
endif()

# Add all source files
file(GLOB SOURCES "*.cpp")
file(GLOB HEADERS "*.h")

message(STATUS "Found ${CMAKE_CXX_COMPILER}")
message(STATUS "Project: ${PROJECT_NAME}")
message(STATUS "Build Type: ${CMAKE_BUILD_TYPE}")
message(STATUS "C++ Standard: ${CMAKE_CXX_STANDARD}")

# Create library
add_library(${PROJECT_NAME}_Engine STATIC ${SOURCES} ${HEADERS})

# Link Qt libraries if enabled
if(ENABLE_QT)
    target_link_libraries(${PROJECT_NAME}_Engine 
        PUBLIC 
        Qt5::Core 
        Qt5::Gui 
        Qt5::Widgets 
        Qt5::Multimedia 
        Qt5::Network
    )
endif()

# Create executable (exclude main.cpp from library, include in exe)
list(REMOVE_ITEM SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp")
add_executable(${PROJECT_NAME} main.cpp ${SOURCES})

# Link libraries to executable
if(ENABLE_QT)
    target_link_libraries(${PROJECT_NAME} 
        PRIVATE 
        Qt5::Core 
        Qt5::Gui 
        Qt5::Widgets 
        Qt5::Multimedia 
        Qt5::Network
    )
endif()

message(STATUS "Build targets: ${PROJECT_NAME}_Engine (library) and ${PROJECT_NAME} (executable)")
