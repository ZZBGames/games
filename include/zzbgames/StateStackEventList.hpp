//
// Created by mathbagu on 19/03/16.
//

#ifndef RICKDANGEROUS_STATESTACKEVENTLIST_HPP
#define RICKDANGEROUS_STATESTACKEVENTLIST_HPP

#include <memory>
#include <vector>

#include <zzbgames/StateStackEvent.hpp>

namespace zzbgames
{

class StateStackEventList
{
public:
    StateStackEventList() = default;

    StateStackEventList(const StateStackEventList& list) = delete;

    ~StateStackEventList() = default;

    StateStackEventList& operator=(const StateStackEventList& list) = delete;

    void addClearEvent();

    void addPopEvent();

    void addPushEvent(const long stateId);

    std::vector<StateStackEvent::Ptr>::const_iterator begin() const;

    void clear();

    std::vector<StateStackEvent::Ptr>::const_iterator end() const;

protected:
    std::vector<StateStackEvent::Ptr> m_events;

};

}

#endif //RICKDANGEROUS_STATESTACKEVENTLIST_HPP
