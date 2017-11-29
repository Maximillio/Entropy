#include "item.h"

Item::Item(float _x, float _y, float _color, int _direction, int _speed, int _size) : m_x(_x), m_y(_y), m_color(_color), m_speed(_speed), m_size(_size)
{
   setDirection(_direction);
   m_bounced = false;
}

float Item::x() const
{
    return m_x;
}

void Item::setX(float _x)
{
    m_x = _x;
}

float Item::y() const
{
    return m_y;
}

void Item::setY(float _y)
{
    m_y = _y;
}

void Item::setDirection(int _direction)
{
    m_directionX = cos((_direction/180.0) * pi);
    m_directionY = sin((_direction/180.0) * pi);
}

void Item::move(double _secondsElapsed)
{
    m_x += m_directionX * m_speed * _secondsElapsed;
    m_y += m_directionY * m_speed * _secondsElapsed;
}

void Item::bounceVerticaly()
{
    m_directionX = -m_directionX;
}

void Item::bounceHorizontally()
{
    m_directionY = -m_directionY;
}

float Item::size() const
{
    return m_size;
}

float Item::speed() const
{
    return m_speed;
}

int Item::color() const
{
    return m_color;
}

void Item::setColor(int color)
{
    m_color = color;
}

bool Item::bounced() const
{
    return m_bounced;
}

void Item::setBounced(bool bounced)
{
    m_bounced = bounced;
}

void Item::setSize(int size)
{
    m_size = size;
}

void Item::setSpeed(int _speed)
{
    m_speed = _speed;
}

float Item::directionX() const
{
    return m_directionX;
}

float Item::directionY() const
{
    return m_directionY;
}
