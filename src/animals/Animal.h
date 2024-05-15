#ifndef ZOOTYCOONCPP_ANIMAL_H
#define ZOOTYCOONCPP_ANIMAL_H
#include <string>
/**
 * Abstract Animal class which is the "parent" class of other animals. All Animal objects such as Mammal, Bird & Reptile have this as their super class.
 */
class Animal {
protected:
    double income;
public:
    Animal(double income);
    double getIncome();
};

#endif
