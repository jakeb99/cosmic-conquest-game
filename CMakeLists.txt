cmake_minimum_required(VERSION 3.10)
project(CosmicConquestGame)

set(CMAKE_CXX_STANDARD 17)

# Find SDL2 and related libraries
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(SDL2_mixer REQUIRED)

find_library(SDL2_IMAGE_LIBRARY NAMES SDL2_image PATHS /opt/homebrew/lib)
find_library(SDL2_TTF_LIBRARY NAMES SDL2_ttf PATHS /opt/homebrew/lib)
find_library(SDL2_MIXER_LIBRARY NAMES SDL2_mixer PATHS /opt/homebrew/lib)

# Include directories
include_directories(/opt/homebrew/include include)

# Print include directories for debugging
message(STATUS "Include Directories: ${SDL2_INCLUDE_DIRS}")

# Source files
file(GLOB SOURCES "src/*.cpp")

# Define executable
add_executable(my_game ${SOURCES})

# Link SDL2 libraries
target_link_libraries(my_game ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARY} ${SDL2_TTF_LIBRARY} ${SDL2_MIXER_LIBRARY})