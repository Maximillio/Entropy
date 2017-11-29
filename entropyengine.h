#ifndef ENTROPYENGINE_H
#define ENTROPYENGINE_H

#include <vector>
#include <item.h>
#include <random>
#include <chrono>
#include <QObject>

using namespace std::chrono;

enum CollisionType {None = 0, Vertical, Horisontal};

class EntropyEngine : public QObject
{
    Q_OBJECT
public:
    EntropyEngine(int _windowHeight, int _windowWidth, int _itemSpeed);
    void update(double _secondsElapsed);
    void changeItemColor(float _x, float _y);
    void createItem(int _x, int _y, int _size);
    void destroyItem(int _x, int _y);
    Item& getItem(const int& _index);
    int itemsCount() const;
    static float getRandomColor();
    static int getRandomDirection();
public slots:
    void onSpeedChanged(const int& _speed);
private:
    void moveItems(double _secondsElapsed);
    void checkCollisions();
    CollisionType checkCollision(Item& _target);
    bool checkIfCoorinatesMatchItem(float _x, float _y, Item &_target);
private:
    std::vector<Item> m_itemList;
    int               m_itemSpeed;
    int               m_windowWidth;
    int               m_windowHeight;
};

#endif // ENTROPYENGINE_H
