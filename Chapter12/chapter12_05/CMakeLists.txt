file(GLOB headers *.h ${headers})
add_executable(chapter12_05 main.cpp ${headers})
include_directories(${CMAKE_SOURCE_DIR}/include)