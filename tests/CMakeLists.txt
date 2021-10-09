cmake_minimum_required (VERSION 3.18.2)

project(tests)

set(OpenCV_STATIC ON)
find_package( OpenCV REQUIRED )

file(GLOB SRC *.?pp)

add_executable(tests ${SRC})

target_include_directories(tests PUBLIC ${OpenCV_INCLUDE_DIRS} ${CMAKE_SOURCE_DIR}/src)

target_link_libraries(tests ${OpenCV_LIBS} puzzled gtest_main)

add_test(NAME tests COMMAND tests)
