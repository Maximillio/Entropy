#ifndef ITEM_H
#define ITEM_H

#include <math.h>
#include <random>
#include <chrono>

using namespace std::chrono;

const double pi = acos(-1);

class Item
{
public:
    Item(float _x, float _y, float _color, int _direction, int _size);
    float x() const;
    void setX(float _x);

    float y() const;
    void setY(float _y);

    float directionX() const;
    float directionY() const;
    void setDirection(int _direction);

    void move(double _secondsElapsed, int _speed);
    void bounceVerticaly();
    void bounceHorizontally();

    float size() const;
    void setSize(int size);

    float speed() const;
    void setSpeed(int _speed);

    int color() const;
    void setColor(int color);

    bool bounced() const;
    void setBounced(bool bounced);

private:
    float       m_x;
    float       m_y;
    float       m_directionX;
    float       m_directionY;
    int         m_color;
    bool        m_bounced;
    int         m_size;
};

#endif // ITEM_H
