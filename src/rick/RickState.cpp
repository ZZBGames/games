//
// Created by mathbagu on 19/03/16.
//

#include <zzbgames/rick/RickState.hpp>

namespace zzbgames
{

namespace rick
{

RickState::RickState(RickStateStack& stateStack, RickContext& context)
    : State(stateStack),
      m_context(context)
{
}

}

}