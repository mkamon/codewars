#pragma once

#include <string>
#include <vector>
#include <tuple>
#include <variant>

/** A Simplistic TCP Finite State Machine (FSM)
https://www.codewars.com/kata/54acc128329e634e9a000362
*/

namespace TCPStateMachine
{
    template <typename... States>
    class StateMachine
    {
    public:
        template <typename State>
        void transitionTo()
        {
            currentState = &std::get<State>(states);
        }

        template <typename Event>
        void handle(const Event &event)
        {
            auto passEventToState = [&event, this] (auto statePtr) {
                statePtr->handle(event).execute(*this);
            };
            std::visit(passEventToState, currentState);
        }

        std::string getCurrentStateName() const 
        {
            std::string result;
            auto getName = [&result] (auto statePtr) {
                result = statePtr -> getName();
            };
            std::visit(std::move(getName), currentState);
            return result;
        }
    private:
        std::tuple<States...> states;
        std::variant<States*...> currentState { &std::get<0>(states) };
    };

    template <typename State>
    struct TransitionTo
    {
        template <typename Machine>
        void execute(Machine &machine)
        {
            machine.template transitionTo<State>();
        }
    };

	struct Nothing
	{
	    template <typename Machine>
	    void execute(Machine &m)
	    {
	    }
	};

    template <typename Action>
    struct ByDefault
    {
        template <typename Event>
        Action handle(const Event&) const 
        {
            return Action{};
        }
    };

    template<typename Event, typename Action>
    struct On
    {
        Action handle(const Event&) const {
            return {};
        }
    };

    template <typename... Handlers>
    struct Will : Handlers...
    {
        using Handlers::handle...;
    };
    
    std::string traverse_TCP_states(const std::vector<std::string> &events);

}