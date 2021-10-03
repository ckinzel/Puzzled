cmake_minimum_required (VERSION 3.18.2)

project(Puzzled)

file(GLOB SRC *.?pp)
set(OpenCV_STATIC ON)
find_package( OpenCV REQUIRED )
add_executable(puzzled ${SRC})

#message(${CMAKE_SOURCE_DIR})
target_include_directories(puzzled PUBLIC ${OpenCV_INCLUDE_DIRS})

target_link_libraries(puzzled ${OpenCV_LIBS})

