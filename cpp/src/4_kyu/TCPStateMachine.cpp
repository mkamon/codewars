#include "TCPStateMachine.hpp"
#include <map>

namespace TCPStateMachine
{
    struct AppPassiveOpenEvent{};
    struct AppActiveOpenEvent{};
    struct AppSendEvent{};
    struct AppCloseEvent{};
    struct AppTimeOutEvent{};
    struct RcvSynEvent{};
    struct RcvAckEvent{};
    struct RcvSynAckEvent{};
    struct RcvFinEvent{};
    struct RcvFinAckEvent{};

    struct ClosedState;
    struct ListenState;
    struct SynSentState;
    struct SynRcvdState;
    struct EstablishedState;
    struct CloseWaitState;
    struct LastAckState;
    struct FinWaitOneState;
    struct FinWaitTwoState;
    struct ClosingState;
    struct TimeWaitState;
    struct ErrorState;
    struct Error
    {
	    template <typename Machine>
	    void execute(Machine &m)
	    {
            m.template transitionTo<ErrorState>();
	    }
    };

    struct ClosedState : public Will<ByDefault<Error>
        , On<AppPassiveOpenEvent, TransitionTo<ListenState>>
        , On<AppActiveOpenEvent, TransitionTo<SynSentState>>
        >
    {
        static std::string getName() { return "CLOSED"; }
    };
    struct ListenState : public Will<ByDefault<Error>
        , On<RcvSynEvent, TransitionTo<SynRcvdState>>
        , On<AppSendEvent, TransitionTo<SynSentState>>
        , On<AppCloseEvent, TransitionTo<ClosedState>>
        >
    {
        static std::string getName() { return "LISTEN"; }
    };
    struct SynSentState : public Will<ByDefault<Error>
        , On<RcvSynEvent, TransitionTo<SynRcvdState>>
        , On<RcvSynAckEvent, TransitionTo<EstablishedState>>
        , On<AppCloseEvent, TransitionTo<ClosedState>>
        >
    {
        static std::string getName() { return "SYN_SENT"; }
    };
    struct SynRcvdState : public Will<ByDefault<Error>
        , On<AppCloseEvent, TransitionTo<FinWaitOneState>>
        , On<RcvAckEvent, TransitionTo<EstablishedState>>
        >
    {
        static std::string getName() { return "SYN_RCVD"; }
    };

    struct EstablishedState : public Will<ByDefault<Error>
        , On<AppCloseEvent, TransitionTo<FinWaitOneState>>
        , On<RcvFinEvent, TransitionTo<CloseWaitState>>
        >
    {
        static std::string getName() { return "ESTABLISHED"; }
    };
    struct CloseWaitState : public Will<ByDefault<Error>
        , On<AppCloseEvent, TransitionTo<LastAckState>>
        >
    {
        static std::string getName() { return "CLOSE_WAIT"; }
    };
    struct LastAckState : public Will<ByDefault<Error>
        , On<RcvAckEvent, TransitionTo<ClosedState>>
        >
    {
        static std::string getName() { return "LAST_ACK"; }
    };
    struct FinWaitOneState : public Will<ByDefault<Error>
        , On<RcvFinEvent, TransitionTo<ClosingState>>
        , On<RcvFinAckEvent, TransitionTo<TimeWaitState>>
        , On<RcvAckEvent, TransitionTo<FinWaitTwoState>>
        >
    {
        static std::string getName() { return "FIN_WAIT_1"; }
    };
    struct FinWaitTwoState : public Will<ByDefault<Error>
        , On<RcvFinEvent, TransitionTo<TimeWaitState>>
        >
    {
        static std::string getName() { return "FIN_WAIT_2"; }
    };
    struct ClosingState : public Will<ByDefault<Error>
        , On<RcvAckEvent, TransitionTo<TimeWaitState>>
        >
    {
        static std::string getName() { return "CLOSING"; }
    };
    struct TimeWaitState : public Will<ByDefault<Error>
        , On<AppTimeOutEvent, TransitionTo<ClosedState>>
        >
    {
        static std::string getName() { return "TIME_WAIT"; }
    };
    struct ErrorState : public Will<ByDefault<Nothing>>
    {
        static std::string getName() { return "ERROR";}
    };

    using TCPMachine = StateMachine<
            ClosedState, ListenState, SynRcvdState, 
            SynSentState, EstablishedState, FinWaitOneState, 
            FinWaitTwoState, ClosingState, TimeWaitState, 
            CloseWaitState, LastAckState, ErrorState
        >;

    class TCPEventManager
    {
      enum class Event
      {
        APP_PASSIVE_OPEN,
        APP_ACTIVE_OPEN,
        APP_SEND,
        APP_CLOSE,
        APP_TIMEOUT,
        RCV_SYN,
        RCV_ACK,
        RCV_SYN_ACK,
        RCV_FIN,
        RCV_FIN_ACK
      };

       const std::map<std::string, Event> nameToEvent = {
           { "APP_PASSIVE_OPEN", Event::APP_PASSIVE_OPEN},
           { "APP_ACTIVE_OPEN", Event::APP_ACTIVE_OPEN},
           { "APP_SEND", Event::APP_SEND},
           { "APP_CLOSE", Event::APP_CLOSE},
           { "APP_TIMEOUT", Event::APP_TIMEOUT},
           { "RCV_SYN", Event::RCV_SYN},
           { "RCV_ACK", Event::RCV_ACK},
           { "RCV_SYN_ACK", Event::RCV_SYN_ACK},
           { "RCV_FIN", Event::RCV_FIN},
           { "RCV_FIN_ACK", Event::RCV_FIN_ACK}
       };
    public:
        void handleNextEvent(TCPMachine &machine, const std::string &eventName) const {
            auto event = nameToEvent.at(eventName);
            switch(event)
            {
                case Event::APP_PASSIVE_OPEN:
                    machine.handle(AppPassiveOpenEvent{});
                    break;
                case Event::APP_ACTIVE_OPEN:
                    machine.handle(AppActiveOpenEvent{});
                    break;
                case Event::APP_SEND:
                    machine.handle(AppSendEvent{});
                    break;
                case Event::APP_CLOSE:
                    machine.handle(AppCloseEvent{});
                    break;
                case Event::APP_TIMEOUT:
                    machine.handle(AppTimeOutEvent{});
                    break;
                case Event::RCV_SYN:
                    machine.handle(RcvSynEvent{});
                    break;
                case Event::RCV_ACK:
                    machine.handle(RcvAckEvent{});
                    break;
                case Event::RCV_SYN_ACK:
                    machine.handle(RcvSynAckEvent{});
                    break;
                case Event::RCV_FIN:
                    machine.handle(RcvFinEvent{});
                    break;
                case Event::RCV_FIN_ACK:
                    machine.handle(RcvFinAckEvent{});
                    break;
            }
        }

    };

    std::string traverse_TCP_states(const std::vector<std::string> &events){
        TCPMachine stateMachine;
        TCPEventManager eventManager;
        for(const auto & event : events){
            eventManager.handleNextEvent(stateMachine, event);
        }
        return stateMachine.getCurrentStateName();
    }
}