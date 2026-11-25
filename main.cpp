#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Player.h"
#include "Room.h"
#include "Item.h"

using namespace std;

int main() {
    // Randomize item placement
    srand(static_cast<unsigned int>(time(0)));

    Player player;
    Room room(20, 10, &player);

    // Create items and place them inside the room
    Item* key = new Item('k', "key");
    Item* coin = new Item('c', "coin");
    Item* potion = new Item('p', "potion");
    Item* torch = new Item('t', "torch");

    room.placeItem(key);
    room.placeItem(coin);
    room.placeItem(potion);
    room.placeItem(torch);

    // Room only stores the item letters, so delete
    // these temporary Item objects after placement
    delete key;
    delete coin;
    delete potion;
    delete torch;

    bool isRunning = true;

    while(isRunning) {

        room.draw();

        char input;

        cout << endl
             << "Please use the WASD keys to move "
             << "or press q to quit: ";

        cin >> input;

        if(input == 'q') {
            isRunning = false;
        } else {
            bool moved = player.move(input, &room);

            if(!moved) {
                cout << "You cannot move in that direction!" << endl;
            }

            // Display inventory after every movement attempt
            player.displayInventory();
        }

        cout << endl;
    }

    cout << "Thanks for playing!" << endl;

    return 0;
}