# base configuration
cmake_minimum_required(VERSION 3.8)
project(pbrain-gomokou)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

# Enable flag for dev
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g3")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Werror -DDEBUG -g3")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall -Werror -g3")

SET(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build (Debug or Release)")

if (CMAKE_BUILD_TYPE MATCHES Debug)
    add_definitions(-DDEBUG)
endif()

# Include directory
set(GOMOKU_INCLUDE ${CMAKE_SOURCE_DIR}/include)
include_directories(${GOMOKU_INCLUDE})

file(GLOB_RECURSE SOURCE_FILES ${CMAKE_SOURCE_DIR}/src/*.cpp)
file(GLOB_RECURSE INCLUDE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp)

# Source files
set(SOURCE_FILES ${SOURCE_FILES} ${INCLUDE_FILES})
#set(SOURCE_FILES ${SOURCE_FILES})

# Executable
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

# Link library
target_link_libraries(${PROJECT_NAME} -static)

# Install
install(TARGETS ${PROJECT_NAME}
        RUNTIME DESTINATION .)
