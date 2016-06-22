cmake_minimum_required(VERSION 3.2.2)
project(untitled)

include_directories(include)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/build")

set(SOURCE_FILES src/main.cpp src/Reflection.cpp)
find_package(RapidJSON)


set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost 1.54.0 COMPONENTS)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    add_executable(untitled ${SOURCE_FILES})
    target_link_libraries(untitled ${Boost_LIBRARIES})
endif()


