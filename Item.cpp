#include "Item.h"

Item::Item(char id, std::string name) {
    this->id = id;
    this->name = name;
}

char Item::getId() {
    return this->id;
}

std::string Item::getName() {
    return this->name;
}

void Item::setId(char id) {
    this->id = id;
}

void Item::setName(std::string name) {
    this->name = name;
}

std::string Item::getNameFromId(char id) {
    if(id == 'k') {
        return "key";
    } else if(id == 'c') {
        return "coin";
    } else if(id == 'p') {
        return "potion";
    } else if(id == 't') {
        return "torch";
    } else if(id == 's') {
        return "stone";
    } else {
        return "unknown item";
    }
}