
find_package( GTest REQUIRED )
include_directories(${GTEST_INCLUDE_DIRS})
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_subdirectory(4_kyu)
add_subdirectory(5_kyu)

