find_package(Catch2 3 REQUIRED)
add_executable(chapter11ca_02 main.cpp)
target_link_libraries(chapter11ca_02 PRIVATE Catch2::Catch2WithMain)
