cmake_minimum_required(VERSION 3.16)

project(app LANGUAGES CXX VERSION 1.0.0)


set(VCPKG_TARGET_TRIPLET "x64-mingw-static") # Required when cross-compiling against static dependencies; in my case: I use gcc on windows.  
include("$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake") # Required if your project depend on vcpkg

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add source files
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS src/*.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})

# Include paths
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# CPR (for HTTP requests)
find_package(cpr REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE cpr::cpr)

