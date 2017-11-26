#ifndef ITEM_H
#define ITEM_H

#include <math.h>
#include <random>
#include <chrono>

using namespace std::chrono;

const double pi = acos(-1);
const float  SPEED = 100; //Pixels per second
const float  SIZE  = 50;

class Item
{
public:
    Item(float _x, float _y, float _color, int _direction);
    float x() const;
    void setX(float _x);

    float y() const;
    void setY(float _y);

    float directionX() const;
    float directionY() const;
    void setDirection(int _direction);

    void move(double _secondsElapsed);
    void bounceVerticaly();
    void bounceHorizontally();

    float size() const;
    float speed() const;

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
};

#endif // ITEM_H
