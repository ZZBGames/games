//
// Created by mathbagu on 19/03/16.
//

#ifndef RICKDANGEROUS_RICKSTATE_HPP
#define RICKDANGEROUS_RICKSTATE_HPP

#include <zzbgames/core/State.hpp>
#include <zzbgames/rick/RickContext.hpp>
#include <zzbgames/rick/RickStateStack.hpp>

namespace zzbgames
{

namespace rick
{

class RickState : public State
{
public:
    RickState(RickStateStack& stateStack, RickContext& context);

    RickState(const RickState& state) = delete;

    virtual ~RickState() = default;

protected:
    RickContext& m_context;

};

}

}


#endif //RICKDANGEROUS_RICKSTATE_HPP
