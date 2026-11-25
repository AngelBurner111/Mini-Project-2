#ifndef ROOM_H
#define ROOM_H

class Player;
class Item;

class Room {
private:
    Player* player;
    int width;
    int height;
    char** map;

public:
    Room(int x, int y, Player* player);
    ~Room();

    void draw();
    bool canMove(int x, int y);

    bool placeItem(Item* item);
    char takeItem(int x, int y);
};

#endif