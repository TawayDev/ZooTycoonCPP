#include "Zoo.h"

Zoo::Zoo(){}

void Zoo::addEnclosure(const Enclosure &enclosure) {
    this->enclosures.push_back(enclosure);
}

int Zoo::getNumEnclosures() const {
    return this->enclosures.size();
}

Enclosure &Zoo::getEnclosure(int index) {
    return this->enclosures.at(index);
}

bool Zoo::removeEnclosure(int index) {
    if (index >= 0 && index < enclosures.size()) {
        enclosures.erase(enclosures.begin() + index);
        return true;
    }
    return false;
};

int Zoo::getTotalFreeCapacity(){
    int total = 0;
    for (const auto& enclosure : this->enclosures) {
        total += enclosure.getMaxCapacity() - enclosure.getCapacity();
    }
    return total;
}

int Zoo::getTotalCapacity() {
    int total = 0;
    for (const auto& enclosure : this->enclosures) {
        total += enclosure.getMaxCapacity();
    }
    return total;
}

int Zoo::getTotalAnimals() {
    int total = 0;
    for (Enclosure enclosure: this->enclosures) {
        total += enclosure.getAnimals().size();
    }
    return total;
}

int Zoo::getTotalProfit() {
    int total = 0;
    for (Enclosure enclosure: this->enclosures) {
        for (const auto &animal: enclosure.getAnimals()) {
            total += animal->getProfit();
        }
    }
    return total;
}
