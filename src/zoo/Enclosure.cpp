#include <iostream>
#include "Enclosure.h"
// Bob the builder
Enclosure::Enclosure() = default;

bool Enclosure::canAddAnimal(Animal &animal) {
    if (capacity < maxCapacity) {
        this->animals.push_back(&animal);
        this->capacity++;
        return true;
    }
    return false;
}

bool Enclosure::isFull() {
    return this->capacity >= this->maxCapacity;
}

bool Enclosure::removeAnimal(int index) {
    if (index >= 0 && index < animals.size()) {
        animals.erase(animals.begin() + index);
        capacity--;
        return true;
    }
    return false;
}

std::vector<Animal*>& Enclosure::getAnimals() {
    return this->animals;
}

int Enclosure::getMaxCapacity() const {
    return maxCapacity;
}

int Enclosure::getCapacity() const {
    return capacity;
}
