
include_directories(${PROJECT_INCLUDE_DIR}/4_kyu)

add_executable( TestConnectFour testConnectFour.cpp )
target_link_libraries(TestConnectFour 4_kyu_lib gtest gtest_main ${GTEST_LIBRARIES} pthread)
add_test( TestConnectFour  TestConnectFour )

add_executable( TestHumanReadableDuration testHumanReadableDuration.cpp )
target_link_libraries( TestHumanReadableDuration 4_kyu_lib gtest gtest_main ${GTEST_LIBRARIES} pthread)
add_test( TestHumanReadableDuration TestHumanReadableDuration )

add_executable( TestSumByFactors testSumByFactors.cpp )
target_link_libraries( TestSumByFactors 4_kyu_lib gtest gtest_main ${GTEST_LIBRARIES} pthread)
add_test( TestSumByFactors TestSumByFactors )

add_executable( TestTwiceLinear testTwiceLinear.cpp )
target_link_libraries( TestTwiceLinear 4_kyu_lib gtest gtest_main ${GTEST_LIBRARIES} pthread)
add_test( TestTwiceLinear TestTwiceLinear )

add_executable( TestTCPStateMachine testTCPStateMachine.cpp )
target_link_libraries( TestTCPStateMachine 4_kyu_lib gtest gtest_main ${GTEST_LIBRARIES} pthread)
add_test( TestTCPStateMachine TestTCPStateMachine )

