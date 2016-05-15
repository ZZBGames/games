//
// Created by mathbagu on 19/03/16.
//

#ifndef ZZBGAMES_STATESTACKEVENT_HPP
#define ZZBGAMES_STATESTACKEVENT_HPP

#include <memory>

namespace zzbgames
{

class StateStackEvent
{
public:
    enum class Type
    {
        PUSH,
        POP,
        CLEAR
    };

    typedef std::unique_ptr<StateStackEvent> Ptr;

public:
    static StateStackEvent::Ptr createPushEvent(const long& stateId);

    static StateStackEvent::Ptr createPopEvent();

    static StateStackEvent::Ptr createClearEvent();

    ~StateStackEvent() = default;

    const long& getStateId() const;

    const StateStackEvent::Type& getType() const;

protected:
    StateStackEvent(const Type& type);

    StateStackEvent(const Type& type, const long& stateId);

    StateStackEvent(const StateStackEvent& stateStackEvent) = delete;

    StateStackEvent& operator=(const StateStackEvent& stateStackEvent) = delete;

protected:
    Type m_type;

    long m_stateId;
};

}

#endif //ZZBGAMES_STATESTACKEVENT_HPP
