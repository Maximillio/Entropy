#ifndef ITEM_H
#define ITEM_H

#include <math.h>
#include <random>

const double pi = acos(-1);

const float SPEED = 10;
const float SIZE  = 30;

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

    void move();
    void bounceVerticaly();
    void bounceHorizontally();

    float size() const;
    float speed() const;

    int color() const;
    void setColor(int color);

private:
    float       m_x;
    float       m_y;
    float       m_directionX;
    float       m_directionY;
    int         m_color;
};

#endif // ITEM_H
