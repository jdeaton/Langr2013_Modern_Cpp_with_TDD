project(ch02)

set(SOURCE_FILES
        main.cpp
        Soundex.h
        SoundexTest.cpp)

add_executable(ch02 ${SOURCE_FILES})
target_link_libraries(ch02 gmock)

