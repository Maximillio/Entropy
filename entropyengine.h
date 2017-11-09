#ifndef ENTROPYENGINE_H
#define ENTROPYENGINE_H

#include <vector>
#include <item.h>
#include <random>
#include <chrono>

const float WINDOW_WIDTH  = 1024;
const float WINDOW_HEIGHT = 800;

enum CollisionType {None = 0, Vertical, Horisontal};

class EntropyEngine
{
public:
    EntropyEngine();
    void update();
    void changeItemColor(float _x, float _y);
    void destroyItem(float _x, float _y);
    void createItem(float _x, float _y);
    Item& getItem(const int& _index);
    int itemsCount() const;
private:
    void moveItems();
    void checkCollisions();
    CollisionType checkCollision(Item& _target);
    bool checkIfCoorinatesMatchItem(float _x, float _y, Item &_target);
private:
    std::vector<Item> m_itemList;
};

#endif // ENTROPYENGINE_H
