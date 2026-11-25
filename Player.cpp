#include "Player.h"
#include "Room.h"
#include <iostream>

using namespace std;

Player::Player() {
    this->x = 3;
    this->y = 3;
}

Player::~Player() {
    // Inventory automatically cleans up its items
}

int Player::getX() {
    return this->x;
}

int Player::getY() {
    return this->y;
}

// Return true if the player moved or false if not
bool Player::move(char direction, Room* room) {

    if(direction == 'w') {
        if(room->canMove(this->x, this->y - 1)) {
            this->y -= 1;
        } else {
            return false;
        }

    } else if(direction == 'a') {
        if(room->canMove(this->x - 1, this->y)) {
            this->x -= 1;
        } else {
            return false;
        }

    } else if(direction == 'd') {
        if(room->canMove(this->x + 1, this->y)) {
            this->x += 1;
        } else {
            return false;
        }

    } else if(direction == 's') {
        if(room->canMove(this->x, this->y + 1)) {
            this->y += 1;
        } else {
            return false;
        }

    } else {
        return false;
    }

    // The player successfully moved.
    // Check whether an item exists at the new position.
    char itemId = room->takeItem(this->x, this->y);

    if(itemId != 0) {
        string itemName = Item::getNameFromId(itemId);

        Item* newItem = new Item(itemId, itemName);

        this->inventory.addItem(newItem);

        cout << "You picked up a " << itemName << "!" << endl;
    }

    return true;
}

void Player::displayInventory() {
    this->inventory.display();
}

bool Player::hasItem(char id) {
    return this->inventory.hasItem(id);
}

bool Player::removeItem(char id) {
    return this->inventory.removeItem(id);
}