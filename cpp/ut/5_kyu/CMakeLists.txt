
include_directories(${PROJECT_INCLUDE_DIR}/5_kyu)

add_executable( testAll_5kyu test_5_kyu_main.cpp )
target_link_libraries( testAll_5kyu 5_kyu_lib gtest gtest_main ${GTEST_LIBRARIES} pthread)
add_test( testAll_5kyu testAll_5kyu )
