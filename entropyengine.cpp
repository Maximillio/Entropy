#include "entropyengine.h"

EntropyEngine::EntropyEngine()
{
    srand(time(0));
    Item* temp = new Item(50,50,(rand() % 0x1000000));
    m_itemList.push_back(*temp);
    temp = new Item(100,100,(rand() % 0x1000000));
    m_itemList.push_back(*temp);
}

void EntropyEngine::update()
{
    moveItems();
    checkCollisions();
}

void EntropyEngine::changeItemColor(float _x, float _y)
{
    for (unsigned i = 0; i < m_itemList.size(); ++i)
    {
        if (checkIfCoorinatesMatchItem(_x, _y, m_itemList[i]))
        {
            m_itemList[i].setColor(rand() % 0x1000000);
        }
    }
}

Item& EntropyEngine::getItem(const int& _index)
{
    if ((_index >= 0)
        && (_index < static_cast<int>(m_itemList.size())))
    {
        return m_itemList[_index];
    }
    else
    {
        throw "Index out of range";
    }
}

int EntropyEngine::itemsCount() const
{
    return m_itemList.size();
}

void EntropyEngine::moveItems()
{
    for (unsigned i = 0; i < m_itemList.size(); ++i)
    {
        m_itemList[i].move();
    }
}

void EntropyEngine::checkCollisions()
{
    for (unsigned i = 0; i < m_itemList.size(); ++i)
    {
        switch (checkCollision(m_itemList[i]))
        {
            case CollisionType::Vertical:
            {
                m_itemList[i].bounceVerticaly();
                break;
            }
            case CollisionType::Horisontal:
            {
                m_itemList[i].bounceHorizontally();
                break;
            }
        default: break;
        }
    }
}

CollisionType EntropyEngine::checkCollision(Item &_target)
{
    if (_target.x() < 0)
    {
        return CollisionType::Vertical;
    }
    if (_target.y() < 0)
    {
        return CollisionType::Horisontal;
    }
    if ((_target.x() + SIZE)  > WINDOW_WIDTH)
    {
        return CollisionType::Vertical;
    }
    if ((_target.y() + SIZE) > WINDOW_HEIGHT)
    {
        return CollisionType::Horisontal;
    }
    return CollisionType::None;
}

bool EntropyEngine::checkIfCoorinatesMatchItem(float _x, float _y, Item& _target)
{
    if ((_x >=_target.x())
        && (_x <= (_target.x() + SIZE))
        && (_y >= _target.y())
        && (_y <= (_target.y() + SIZE)))
    {
        return true;
    }
    else
    {
        return false;
    }
}
