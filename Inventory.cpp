#include "Inventory.h"
#include <iostream>

using namespace std;

Inventory::Inventory() {
    this->arraySize = 2;
    this->numberOfItems = 0;
    this->items = new Item*[arraySize];
}

bool Inventory::addItem(Item* item) {
    if(item == nullptr) {
        return false;
    }

    // If the array is full, double its size
    if(this->numberOfItems >= this->arraySize) {
        int newArraySize = this->arraySize * 2;

        Item** newItems = new Item*[newArraySize];

        for(int i = 0; i < this->numberOfItems; i++) {
            newItems[i] = this->items[i];
        }

        delete[] this->items;

        this->items = newItems;
        this->arraySize = newArraySize;
    }

    this->items[this->numberOfItems] = item;
    this->numberOfItems++;

    return true;
}

bool Inventory::removeItem(char id) {
    for(int i = 0; i < this->numberOfItems; i++) {
        if(this->items[i]->getId() == id) {

            // Delete the item being removed
            delete this->items[i];

            // Shift the remaining pointers left
            for(int j = i; j < this->numberOfItems - 1; j++) {
                this->items[j] = this->items[j + 1];
            }

            this->numberOfItems--;

            return true;
        }
    }

    return false;
}

bool Inventory::hasItem(char id) {
    for(int i = 0; i < this->numberOfItems; i++) {
        if(this->items[i]->getId() == id) {
            return true;
        }
    }

    return false;
}

void Inventory::display() {
    cout << "Inventory: ";

    if(this->numberOfItems == 0) {
        cout << "Empty";
    } else {
        for(int i = 0; i < this->numberOfItems; i++) {
            cout << this->items[i]->getName();

            if(i < this->numberOfItems - 1) {
                cout << ", ";
            }
        }
    }

    cout << endl;
}

Inventory::~Inventory() {
    // Delete every item the inventory owns
    for(int i = 0; i < this->numberOfItems; i++) {
        delete this->items[i];
    }

    // Delete the pointer array itself
    delete[] this->items;
}