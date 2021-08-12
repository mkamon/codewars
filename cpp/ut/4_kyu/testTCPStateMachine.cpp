#include <gtest/gtest.h>

#include "TCPStateMachine.hpp"

using State = std::string;
using Transitions = std::vector<State> ;
class TCPStatesTransitions 
    : public ::testing::TestWithParam<std::tuple<Transitions, State>>
{};

TEST_P(TCPStatesTransitions, onGivenStatesTransitionsShouldStayInExpectedState)
{
    //given
    const auto &transitions = std::get<0>(GetParam());
    const auto &expectedState = std::get<1>(GetParam());
    //when 
    auto resultState = TCPStateMachine::traverse_TCP_states(transitions);
    //then
    ASSERT_EQ(resultState, expectedState);
}

INSTANTIATE_TEST_CASE_P(
    TestTCPStateMachine, 
    TCPStatesTransitions,
    ::testing::Values(
        std::make_tuple(Transitions({"APP_PASSIVE_OPEN", "APP_SEND", "RCV_SYN_ACK"}), "ESTABLISHED" ),
        std::make_tuple(Transitions({"APP_ACTIVE_OPEN"}), "SYN_SENT"),
        std::make_tuple(Transitions({"APP_ACTIVE_OPEN", "RCV_SYN_ACK", "APP_CLOSE", "RCV_FIN_ACK", "RCV_ACK"}), "ERROR" )
    ));
