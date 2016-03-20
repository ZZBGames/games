//
// Created by mathbagu on 19/03/16.
//

#include <zzbgames/StateStackEvent.hpp>

namespace zzbgames
{

StateStackEvent::Ptr StateStackEvent::createPushEvent(const long& stateId)
{
    return StateStackEvent::Ptr(new StateStackEvent(Type::PUSH, stateId));
}

StateStackEvent::Ptr StateStackEvent::createPopEvent()
{
    return StateStackEvent::Ptr(new StateStackEvent(Type::POP));
}

StateStackEvent::Ptr StateStackEvent::createClearEvent()
{
    return StateStackEvent::Ptr(new StateStackEvent(Type::CLEAR));
}

const long& StateStackEvent::getStateId() const
{
    return m_stateId;
}

const StateStackEvent::Type& StateStackEvent::getType() const
{
    return m_type;
}

StateStackEvent::StateStackEvent(const Type& type)
    : StateStackEvent(type, -1)
{
}

StateStackEvent::StateStackEvent(const Type& type, const long& stateId)
    : m_type(type),
      m_stateId(stateId)
{
}

}