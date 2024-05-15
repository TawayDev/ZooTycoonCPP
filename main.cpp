#include <iostream>
#include "src/zoo/Zoo.h"

int main() {

    // My finals week or my final week ? STAY TUNED!

    Zoo zoo;
    bool run = true;
    do {
        std::cout
        << "Enlosures: " << zoo.getNumEnclosures()
        << "+-> Capacity " << (zoo.getTotalCapacity() - zoo.getTotalFreeCapacity()) << "/" << zoo.getTotalCapacity()
        << "+-> Animals " << zoo.getTotalAnimals()
        << "+-> Profit " << zoo.getTotalProfit()
        << std::endl;
    } while(run);
    return 0;
}
