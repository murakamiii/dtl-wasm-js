cmake_minimum_required(VERSION 3.10)
enable_language(CXX)
project(DTL_BIND)

set(main_src
  bind.cpp
  dtlwandbox/DTL.hpp
)

add_definitions("-std=c++17 -Wall --pedantic-errors") 
add_executable(a.out ${main_src})

#以下のメッセージが出てきて死ぬ
#Found package configuration file:
#
#   /repopath/DungeonTemplateLibrary-js/dtl/cmake/modules/dtl-config.cmake
#
#but it set DTL_FOUND to FALSE so package "DTL" is considered to be NOT FOUND.
#
# set(CMAKE_PREFIX_PATH dtlcpp/cmake/modules)
# find_package(DTL)
# include_directories(${DTL_INCLUDE_DIRS})
# target_link_libraries(a.out ${DTL_LIBRARIES})

# emcc -s EXIT_RUNTIME=1 -s ALLOW_MEMORY_GROWTH=1 --bind -o dtl.js ../src/bind.cpp && node ex.js