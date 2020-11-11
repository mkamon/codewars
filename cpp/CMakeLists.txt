cmake_minimum_required (VERSION 3.0)
project( CODEWARS )

find_package( GTest REQUIRED )
include_directories(${GTEST_INCLUDE_DIRS})

enable_testing()
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
add_definitions( "-Wall -pthread -std=c++11 -g" )

include_directories(include/5_kyu)
add_library( 5_kyu_lib
		src/5_kyu/double_cola.cpp
		src/5_kyu/coding_with_squared_strings.cpp
		src/5_kyu/factorial_decomposition.cpp
 )

include_directories(include/4_kyu)
add_library( 4_kyu_lib
		src/4_kyu/human_readable_duration_format.cpp
		src/4_kyu/sum_by_factors.cpp
		src/4_kyu/connect_four.cpp
)

add_executable( testAll_5kyu ./src/test_5_kyu_main.cpp )
target_link_libraries( testAll_5kyu 5_kyu_lib gtest gtest_main ${GTEST_LIBRARIES} pthread)
add_test( testAll_5kyu testAll_5kyu )

add_executable( testAll_4kyu ./src/test_4_kyu_main.cpp )
target_link_libraries( testAll_4kyu 4_kyu_lib gtest gtest_main ${GTEST_LIBRARIES} pthread)
add_test( testAll_4kyu testAll_4kyu )


