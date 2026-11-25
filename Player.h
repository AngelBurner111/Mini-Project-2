#ifndef PLAYER_H
#define PLAYER_H

#include "Inventory.h"

class Room;

// This is meant for the Player's position
// The Player owns an Inventory
class Player {
private:
    int x;
    int y;
    Inventory inventory;

public:
    Player();
    ~Player();

    int getX();
    int getY();

    bool move(char direction, Room* room);

    void displayInventory();
    bool hasItem(char id);
    bool removeItem(char id);
};

#endif