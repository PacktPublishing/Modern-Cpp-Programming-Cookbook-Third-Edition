find_package(Catch2 3 REQUIRED)
add_executable(chapter11ca_04 main.cpp)
target_link_libraries(chapter11ca_04 PRIVATE Catch2::Catch2WithMain)
