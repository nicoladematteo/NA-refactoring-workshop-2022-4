#pragma once

#include <list>
#include <memory>
#include <functional>

#include "IEventHandler.hpp"
#include "SnakeInterface.hpp"


class IPort;

namespace Snake
{

class SnakeWorld 
{
    
public:
    SnakeWorld(IPort& p_displayPort, IPort& p_foodPort);
    bool ReadPosition(std::istringstream& istr);
    bool IsPositionOutsideMap(int x, int y) const;
    void sendPlaceNewFood(int x, int y);

private:
    std::pair<int, int> m_mapDimension;
    std::pair<int, int> m_foodPosition;
    IPort& m_displayPort;
    IPort& m_foodPort;

};
}