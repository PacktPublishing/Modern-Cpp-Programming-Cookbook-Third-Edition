file(GLOB headers *.h ${headers})
add_executable(chapter12_12 main.cpp ${headers})
include_directories(${CMAKE_SOURCE_DIR}/include)
