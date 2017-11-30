#ifndef ENTROPYENGINE_H
#define ENTROPYENGINE_H

#include <vector>
#include <item.h>
#include <random>
#include <chrono>
#include <QObject>
#include <QDebug>

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
    int destroyItem(int _x, int _y);
    void destroyAll();
    Item& getItem(const int& _index);
    int itemsCount() const;
    bool checkIfCoorinatesMatchItem(int _x, int _y);

    static float getRandomColor();
    static int getRandomDirection();
public slots:
    void onSpeedChanged(const int& _speed);
private:
    Item* getItemByCoordinates(int _x, int _y);
    void moveItems(double _secondsElapsed);
    void checkCollisions();
    CollisionType checkCollision(Item& _target);   
private:
    std::vector<Item> m_itemList;
    int               m_windowHeight;
    int               m_windowWidth;
    int               m_itemSpeed;   
};

#endif // ENTROPYENGINE_H
