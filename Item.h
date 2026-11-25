#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item {
private:
    char id;
    std::string name;

public:
    Item(char id = '*', std::string name = "empty space");

    char getId();
    std::string getName();

    void setId(char id);
    void setName(std::string name);

    static std::string getNameFromId(char id);
};

#endif