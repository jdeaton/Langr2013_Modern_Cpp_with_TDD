cmake_minimum_required(VERSION 3.8)
project(Langr2013_Modern_Cpp_with_TDD)

set(CMAKE_CXX_STANDARD 11)

# Google Mock/Test include/lib directories.
include_directories(/Users/deatonjd/Code/Utilities/googletest-release-1.8.0/include)
link_directories(/Users/deatonjd/Code/Utilities/googletest-release-1.8.0/lib)

add_subdirectory(ch01)