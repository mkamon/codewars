
find_package( GTest REQUIRED )
include_directories(${GTEST_INCLUDE_DIRS})
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(${PROJECT_INCLUDE_DIR}/5_kyu)
include_directories(${PROJECT_INCLUDE_DIR}/4_kyu)

add_executable( testAll_5kyu test_5_kyu_main.cpp )
target_link_libraries( testAll_5kyu 5_kyu_lib gtest gtest_main ${GTEST_LIBRARIES} pthread)
add_test( testAll_5kyu testAll_5kyu )

add_executable( testAll_4kyu test_4_kyu_main.cpp )
target_link_libraries( testAll_4kyu 4_kyu_lib gtest gtest_main ${GTEST_LIBRARIES} pthread)
add_test( testAll_4kyu testAll_4kyu )

