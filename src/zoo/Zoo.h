#ifndef ZOOTYCOONCPP_ZOO_H
#define ZOOTYCOONCPP_ZOO_H

#include <vector>
#include "Enclosure.h"
/**
 * Basically a class that holds a vector of enclosures because if you really think about it that's exactly what a Zoo is.
 */
class Zoo {
private:
    std::vector<Enclosure> enclosures;

public:
    Zoo();
    /**
     * Adds enclosure to the list of enclosures.
     * @param enclosure
     */
    void addEnclosure(const Enclosure& enclosure);
    /**
     * @return Amount of enclosures in current Zoo object.
     */
    int getNumEnclosures() const;
    /**
     * @param index
     * @return All of the Enclosures
     */
    Enclosure& getEnclosure(int index);
    /**
     * Removes enclosure from array at index
     * @param index
     * @return True if removed, false otherwise
     */
    bool removeEnclosure(int index);
    /**
     * Returns total capacity unused of all enclosures.
     * @return
     */
    int getTotalFreeCapacity();
    /**
     * Returns total capacity used of all enclosures.
     * @return
     */
    int getTotalCapacity();

    int getTotalAnimals();

    double getTotalProfit();
};

#endif
