file(GLOB headers *.h ${headers})

include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${LIBCORO_PATH}/include)
link_directories(${LIBCORO_PATH}/lib)

add_executable(chapter12_12_2 main.cpp ${headers})


if(MSVC) 
  target_link_libraries(chapter12_12_2 debug libcoro.lib)
  target_link_libraries(chapter12_12_2 optimized libcoro.lib)
endif()
