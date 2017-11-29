#include "entropyengine.h"

EntropyEngine::EntropyEngine()
{
    srand(time(0));
}

void EntropyEngine::update(double _secondsElapsed)
{
    moveItems(_secondsElapsed);
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

void EntropyEngine::createItem(int _x, int _y, int _speed, int _size)
{
    auto temp = new Item(_x, _y, EntropyEngine::getRandomColor(), EntropyEngine::getRandomDirection(), _speed, _size);
    m_itemList.push_back(*temp);
}

void EntropyEngine::destroyItem(int _x, int _y)
{
    for(auto i = m_itemList.begin(); i != m_itemList.end(); ++i)
    {
        if ((i->x() == _x) && (i->y() == _y))
        {
            m_itemList.erase(i);
            break;
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

float EntropyEngine::getRandomColor()
{

    return (((rand() % 0x100) + ((rand() % 0x100) * 256) + ((rand() % 0x100) * 256 * 256)));
}

int EntropyEngine::getRandomDirection()
{
    return rand() % 360;
}

void EntropyEngine::moveItems(double _secondsElapsed)
{
    for (unsigned i = 0; i < m_itemList.size(); ++i)
    {
        m_itemList[i].move(_secondsElapsed);
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

CollisionType EntropyEngine::checkCollision(Item& _target)
{
    if (!_target.bounced())
    {
        if (_target.x() <= 0)
        {
            _target.setBounced(true);
            return CollisionType::Vertical;
        }
        if (_target.y() <= 0)
        {
            _target.setBounced(true);
            return CollisionType::Horisontal;
        }
        if ((_target.x() + _target.size())  >= WINDOW_WIDTH)
        {
            _target.setBounced(true);
            return CollisionType::Vertical;
        }
        if ((_target.y() + _target.size()) >= WINDOW_HEIGHT)
        {
            _target.setBounced(true);
            return CollisionType::Horisontal;
        }
    }
    else
    {
        _target.setBounced(false);
    }
    return CollisionType::None;
}

bool EntropyEngine::checkIfCoorinatesMatchItem(float _x, float _y, Item& _target)
{
    if ((_x >=_target.x())
        && (_x <= (_target.x() + _target.size()))
        && (_y >= _target.y())
        && (_y <= (_target.y() + _target.size())))
    {
        return true;
    }

    return false;
}
