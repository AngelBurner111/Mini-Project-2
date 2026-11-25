#include "Room.h"
#include "Player.h"
#include "Item.h"
#include <iostream>
#include <cstdlib>

using namespace std;

Room::Room(int x, int y, Player* player) {
    this->player = player;

    this->width = x;
    this->height = y;

    this->map = new char*[y];

    for(int outerCounter = 0; outerCounter < y; outerCounter++) {
        this->map[outerCounter] = new char[x];

        for(int innerCounter = 0; innerCounter < x; innerCounter++) {

            if(outerCounter == 0 ||
               outerCounter == (y - 1) ||
               innerCounter == 0 ||
               innerCounter == (x - 1)) {

                this->map[outerCounter][innerCounter] = '#';

            } else {
                this->map[outerCounter][innerCounter] = ' ';
            }
        }
    }
}

Room::~Room() {
    // Delete each row of the map
    for(int i = 0; i < this->height; i++) {
        delete[] this->map[i];
    }

    // Delete the array of rows
    delete[] this->map;
}

bool Room::canMove(int x, int y) {
    // Prevent movement outside the map
    if(x < 0 || x >= this->width ||
       y < 0 || y >= this->height) {
        return false;
    }

    if(this->map[y][x] != '#') {
        return true;
    } else {
        return false;
    }
}

bool Room::placeItem(Item* item) {
    if(item == nullptr) {
        return false;
    }

    // Try random open spaces
    for(int attempt = 0; attempt < 100; attempt++) {
        int x = rand() % this->width;
        int y = rand() % this->height;

        if(this->map[y][x] == ' ' &&
           !(this->player->getX() == x &&
             this->player->getY() == y)) {

            this->map[y][x] = item->getId();
            return true;
        }
    }

    // If random attempts fail, search the map
    for(int y = 1; y < this->height - 1; y++) {
        for(int x = 1; x < this->width - 1; x++) {

            if(this->map[y][x] == ' ' &&
               !(this->player->getX() == x &&
                 this->player->getY() == y)) {

                this->map[y][x] = item->getId();
                return true;
            }
        }
    }

    return false;
}

char Room::takeItem(int x, int y) {
    // Make sure the position is within the map
    if(x < 0 || x >= this->width ||
       y < 0 || y >= this->height) {
        return 0;
    }

    char itemId = this->map[y][x];

    // An open space or wall isn't an item
    if(itemId == ' ' || itemId == '#') {
        return 0;
    }

    // Remove the item from the map
    this->map[y][x] = ' ';

    return itemId;
}

void Room::draw() {
    for(int outerCounter = 0; outerCounter < height; outerCounter++) {

        for(int innerCounter = 0; innerCounter < width; innerCounter++) {

            // Check if the player is on this spot
            if(this->player->getX() == innerCounter &&
               this->player->getY() == outerCounter) {

                cout << '@';

            } else {
                cout << this->map[outerCounter][innerCounter];
            }
        }

        cout << endl;
    }
}