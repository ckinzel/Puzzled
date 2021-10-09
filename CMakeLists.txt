cmake_minimum_required (VERSION 3.18.2)

project(Puzzled)

enable_testing()

set(OpenCV_STATIC ON)
find_package( OpenCV REQUIRED )
add_executable(main main.cpp)

target_include_directories(main PUBLIC ${OpenCV_INCLUDE_DIRS} ${CMAKE_SOURCE_DIR}/src)

target_link_libraries(main ${OpenCV_LIBS} puzzled)

add_subdirectory(src)
add_subdirectory(googletest)
add_subdirectory(tests)
