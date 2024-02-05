find_package(Catch2 3 REQUIRED)
include_directories(${CMAKE_SOURCE_DIR}/include)
add_executable(chapter11ca_03 main.cpp)
target_link_libraries(chapter11ca_03 PRIVATE Catch2::Catch2WithMain)
