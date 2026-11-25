#ifndef INVENTORY_H
#define INVENTORY_H

#include "Item.h"

class Inventory {
private:
    Item** items;
    int numberOfItems;
    int arraySize;

public:
    bool addItem(Item* item);
    bool removeItem(char id);
    bool hasItem(char id);
    void display();

    Inventory();
    ~Inventory();

    // Inventory cannot be copied
    Inventory(const Inventory&) = delete;
    Inventory& operator=(const Inventory&) = delete;
};

#endif