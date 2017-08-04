project(ch01)

set(SOURCE_FILES main.cpp)

add_executable(ch01 ${SOURCE_FILES})
target_link_libraries(ch01 gtest)
target_link_libraries(ch01 gtest_main)
target_link_libraries(ch01 gmock)
target_link_libraries(ch01 gmock_main)