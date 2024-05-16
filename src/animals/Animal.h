#ifndef ZOOTYCOONCPP_ANIMAL_H
#define ZOOTYCOONCPP_ANIMAL_H
#include <string>
/**
 * Abstract Animal class which is the "parent" class of other animals. All Animal objects such as Mammal, Bird & Reptile have this as their super class.
 */
class Animal {
public:
    // NOTE: i could not be bothered to create a cpp class for one getter for every child of this class. fuck that.
    double income = 0;
    explicit Animal(double income){
        this->income = income;
    };
};

#endif
