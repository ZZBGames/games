//
// Created by mathbagu on 19/03/16.
//

#ifndef RICKDANGEROUS_RICKSTATESTACK_HPP
#define RICKDANGEROUS_RICKSTATESTACK_HPP

#include <map>

#include <zzbgames/StateStack.hpp>
#include <zzbgames/rick/RickContext.hpp>

namespace zzbgames
{

namespace rick
{

class RickStateStack : public StateStack
{
public:
    RickStateStack(const RickContext& context);

    virtual ~RickStateStack() = default;

    template<typename STATE>
    void registerState(const long stateId);

protected:
    RickContext m_context;
};

template<typename STATE>
void RickStateStack::registerState(const long stateId)
{
    m_stateFactories[stateId] = [this]() {
        return State::Ptr(new STATE(*this, m_context));
    };
}

}

}

#endif //RICKDANGEROUS_RICKSTATESTACK_HPP
