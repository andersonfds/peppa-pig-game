# Project setup
cmake_minimum_required(VERSION 3.15)
project(PeppaPig)

# GET ALL FILES FROM src FOLDER AND ADD TO VARIABLE
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Compiling options
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_COMPILER "g++")
set(PGE_VERSION "v2.23")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(HEADERS_DIR ${CMAKE_SOURCE_DIR}/include)

# Dependencies
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(PNG REQUIRED)

# Downloading headers from github
function(download_git_release USER REPO TAG OUTPUT)
    set(FILE_NAME "${HEADERS_DIR}/${OUTPUT}")
    if (NOT EXISTS "${FILE_NAME}")
        message(STATUS "Downloading ${USER}/${REPO} ${TAG} to ${OUTPUT}")
        file(DOWNLOAD "https://github.com/${USER}/${REPO}/releases/download/${TAG}/${OUTPUT}" "${FILE_NAME}")
    endif()
endfunction()

# Downloading headers
download_git_release("OneLoneCoder" "olcPixelGameEngine" ${PGE_VERSION} "olcPixelGameEngine.h")

# include standard libraries
add_executable(${PROJECT_NAME} ${SOURCES})

include_directories(${HEADERS_DIR} ${PNG_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${GLUT_LIBRARIES} ${OPENGL_LIBRARIES} ${PNG_LIBRARY})
