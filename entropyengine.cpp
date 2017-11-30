#include "entropyengine.h"

EntropyEngine::EntropyEngine(int _windowHeight, int _windowWidth, int _itemSpeed)
    : m_windowHeight(_windowHeight), m_windowWidth(_windowWidth), m_itemSpeed(_itemSpeed)
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
    Item* itemToChange = nullptr;
    itemToChange = getItemByCoordinates(_x, _y);
    if (itemToChange)
    {
        itemToChange->setColor(EntropyEngine::getRandomColor());
    }
}

void EntropyEngine::createItem(int _x, int _y, int _size)
{
    auto temp = new Item(_x, _y, EntropyEngine::getRandomColor(), EntropyEngine::getRandomDirection(), _size);
    m_itemList.push_back(*temp);
}

int EntropyEngine::destroyItem(int _x, int _y)
{
    int index = 0;
    for (auto i = m_itemList.begin(); i != m_itemList.end(); ++i, ++index)
    {
        if ((_x >=i->x())
            && (_x <= (i->x() + i->size()))
            && (_y >= i->y())
            && (_y <= (i->y() + i->size())))
        {
            m_itemList.erase(i);
            return index;
        }
    }
    return -1;
}

void EntropyEngine::destroyAll()
{
    m_itemList.erase(m_itemList.begin(), m_itemList.end());
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

void EntropyEngine::onSpeedChanged(const int &_speed)
{
    m_itemSpeed = _speed;
}

void EntropyEngine::moveItems(double _secondsElapsed)
{
    for (unsigned i = 0; i < m_itemList.size(); ++i)
    {
        m_itemList[i].move(_secondsElapsed, m_itemSpeed);
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
        if ((_target.x() + _target.size())  >= m_windowWidth)
        {
            _target.setBounced(true);
            return CollisionType::Vertical;
        }
        if ((_target.y() + _target.size()) >= m_windowHeight)
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

bool EntropyEngine::checkIfCoorinatesMatchItem(int _x, int _y)
{
    for (Item i : m_itemList)
    {
        if ((_x >=i.x())
            && (_x <= (i.x() + i.size()))
            && (_y >= i.y())
            && (_y <= (i.y() + i.size())))
        {
            return true;
        }
    }
    return false;
}

Item* EntropyEngine::getItemByCoordinates(int _x, int _y)
{
    for (unsigned i = 0; i < m_itemList.size(); ++i)
    {
        if ((_x >=m_itemList[i].x())
            && (_x <= (m_itemList[i].x() + m_itemList[i].size()))
            && (_y >= m_itemList[i].y())
            && (_y <= (m_itemList[i].y() + m_itemList[i].size())))
        {
            return &m_itemList[i];
        }
    }
    return nullptr;
}
