#ifndef ZOOTYCOONCPP_ENCLOSURE_H
#define ZOOTYCOONCPP_ENCLOSURE_H

#include <vector>
#include "../animals/Animal.h"

class Enclosure {
private:
    /**
     * We assume that we live in a perfect utopia where every animal type can co-exist in the same enclosure. No animals will be harmed because fairytale rules apply.
     */
    std::vector<Animal*> animals;
    int maxCapacity;
    int capacity;

public:
    explicit Enclosure(int maxCapacity);

    /**
    * Adds the animal reference to the animal vector and returns true. If the enclosure is at capacity no animal has been added, false returned.
    * @param animal
    * @return True if added, false otherwise.
    */
    bool canAddAnimal(Animal &animal);

    /**
     * @return True if the enclosure is full and no more animals can be added.
     */
    bool isFull();

    /**
     * Removes the animal at index param
     * @param index
     * @return True if animal has been found and removed, false otherwise.
     */
    bool removeAnimal(int index);

    std::vector<Animal *> &getAnimals();

    int getMaxCapacity() const;

    int getCapacity() const;
};
#endif
