#include "SnakeWorld.hpp"
#include "IPort.hpp"
#include "EventT.hpp"
#include <sstream>
#include "SnakeInterface.hpp"

namespace Snake
{
    SnakeWorld::SnakeWorld(IPort& p_displayPort, IPort& p_foodPort)
    : m_displayPort(p_displayPort),
      m_foodPort(p_foodPort)
{

}

bool SnakeWorld::ReadPosition(std::istringstream& istr)
{
    char w, f, s;

    int width, height;
    int foodX, foodY;
    istr >> w >> width >> height >> f >> foodX >> foodY >> s;

    if (w == 'W' and f == 'F' and s == 'S') {
        m_mapDimension = std::make_pair(width, height);
        m_foodPosition = std::make_pair(foodX, foodY);
        return true;
    }
    return false;
}

bool SnakeWorld::IsPositionOutsideMap(int x, int y) const{
    return x < 0 || y < 0 || x >= m_mapDimension.first || y >= m_mapDimension.second;
}

void SnakeWorld::sendPlaceNewFood(int x, int y)
{
    m_foodPosition = std::make_pair(x, y);

    DisplayInd placeNewFood;
    placeNewFood.x = x;
    placeNewFood.y = y;
    placeNewFood.value = Cell_FOOD;

    m_displayPort.send(std::make_unique<EventT<DisplayInd>>(placeNewFood));
}


}