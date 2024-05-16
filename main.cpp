#include <iostream>
#include "src/zoo/Zoo.h"
#include "src/animals/Mammal.h"
#include "src/animals/Bird.h"
#include "src/animals/Reptile.h"

// https://stackoverflow.com/questions/228617/how-do-i-clear-the-console-in-both-windows-and-linux-using-c
// FIXME: Does not work in dev console in Clion, can't run exe on win11 because libstdc++-6.dll is not present on my system.
//#ifdef _WIN32
//#define CLEAR "cls"
//#else //In any other OS
//#define CLEAR "clear"
//#endif

int main() {
    // static stuffs.
    Mammal staticMammal;
    Bird staticBird;
    Reptile staticReptile;
    double money = 3000;
    int day = 1;
    // Looking back I could just do an enum of prices and other data and then do a counter
    // and just multiply it but that would not be compliant with the project criteria KEKW

    Zoo zoo;
    Enclosure enclosure;
    zoo.addEnclosure(enclosure);
    Mammal mammal;
    zoo.getEnclosure(0).canAddAnimal(mammal);
    bool run = true;
    do {
        std::string input;
        std::cout << "<===//===<[ DAY " << day << " ]>===\\\\===>" << std::endl;
        std::cout << "--[ INFO ]--" << std::endl;
        std::cout << "Money: " << money << std::endl;
        std::cout << "Enclosures: " << zoo.getNumEnclosures() << std::endl;
        // To calculate space used ... what the fuck did I cook up ?
        std::cout << "+-> Capacity: " << (zoo.getTotalCapacity() - (zoo.getTotalCapacity() - zoo.getTotalFreeCapacity())) << "/" << zoo.getTotalCapacity() << std::endl;
        std::cout << "+-> Animals: " << zoo.getTotalAnimals() << std::endl;
        std::cout << "+-> Profit per day: " << zoo.getTotalProfit() << std::endl;

        std::cout << std::endl;
        std::cout << "--[ BUY ]--" << std::endl;
        std::cout << "<E>nclosure: " << 1000 << std::endl;
        std::cout << "<M>ammal: " << 400 << std::endl;
        std::cout << "<R>eptile: " << 200 << std::endl;
        std::cout << "<B>ird: " << 100 << std::endl;

        std::cout << std::endl;
        std::cout << "--[ OTHER ]--" << std::endl;
        std::cout << "e<X>it" << std::endl;
        std::cout << "<S>kip" << std::endl;

        std::getline(std::cin, input);
        switch(tolower(input[0])) {
            case 'e':
                // Buy enclosure
                if(money - 1000 >= 0) {
                    Enclosure e;
                    zoo.addEnclosure(e);
                    std::cout << "Enclosure bought!" << std::endl;
                } else {
                    std::cout << "Insufficient funds to buy an enclosure." << std::endl;
                }
                break;
            case 'm':
                // Buy mammal
                if (money - 400 >= 0) {
                    Mammal m;
                    if (zoo.getEnclosure(0).canAddAnimal(m)) {
                        money -= 400;
                        std::cout << "Mammal bought!" << std::endl;
                    } else {
                        std::cout << "Enclosure is at capacity. Cannot add mammal." << std::endl;
                    }
                } else {
                    std::cout << "Insufficient funds to buy a mammal." << std::endl;
                }
                break;
            case 'r':
                // Buy reptile
                if (money - 200 >= 0) {
                    Reptile r;
                    if (zoo.getEnclosure(0).canAddAnimal(r)) {
                        money -= 200;
                        std::cout << "Reptile bought!" << std::endl;
                    } else {
                        std::cout << "Enclosure is at capacity. Cannot add reptile." << std::endl;
                    }
                } else {
                    std::cout << "Insufficient funds to buy a reptile." << std::endl;
                }
                break;
            case 'b':
                // Buy bird
                if (money - 100 >= 0) {
                    Bird b;
                    if (zoo.getEnclosure(0).canAddAnimal(b)) {
                        money -= 100;
                        std::cout << "Bird bought!" << std::endl;
                    } else {
                        std::cout << "Enclosure is at capacity. Cannot add bird." << std::endl;
                    }
                } else {
                    std::cout << "Insufficient funds to buy a bird." << std::endl;
                }
                break;
            case 'x':
                run = false;
                std::cout << "Bye!" << std::endl;
                break;
            case 's':
                // skip day
                break;
            default:
                std::cout << input[0] << " is not a valid option. Please try again!" << std::endl;
                break;
        }
//        system(CLEAR);
        money += zoo.getTotalProfit();
        day++;
    } while(run);
    return 0;
}
