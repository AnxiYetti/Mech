#include <iostream>
#include <string>
#include <random>
#include "mech.h"
#include "weapon.h"

// Function to generate random numbers for use with dealDamage
int randomDmgNumber(std::default_random_engine& gen, Weapon& weapon) {
    std::uniform_int_distribution<int> distribution(weapon.getMinDamage(), weapon.getMaxDamage());
    int rngDamage = distribution(gen);
    return rngDamage;
}

// Controls the combat loop for gauntlet runs
void combat(Mech& mech1, Mech mech2, Weapon& weapon1, Weapon& weapon2, std::default_random_engine& gen) {
    int rounds = 0;
    // Run combat until mech 2 is destroyed.
    while (!mech2.isDestroyed()) {
        std::cout << "Round " << rounds+1 << "!" << '\n'
                  << mech1.getName() << " swings " << weapon1.getName() << " at " << mech2.getName() << "!" <<  std::endl;
        int mech1rngDmg = randomDmgNumber(gen, weapon1);
        std::cout << mech1.getName() << " dealt " << mech1rngDmg << " damage to " << mech2.getName() + "." << std::endl; 
        mech1.dealDamage(mech2, mech1rngDmg);
        std::cout << mech2.getName() + "'s" << " health: " << mech2.getHealth() << std::endl;
        if (mech2.isDestroyed()) {
            std::cout << mech2.getName() << " has been destroyed!" << std::endl;
            break;
        }
        std::cout << mech2.getName() << " responds with a " << weapon2.getName() + "!" << std::endl;
        int mech2RngDmg = randomDmgNumber(gen, weapon2);
        std::cout << mech2.getName() << " dealt " << mech2RngDmg << " damage!" << std::endl;
        mech2.dealDamage(mech1, mech2RngDmg); // Needs nothing now! lol
        std::cout << mech1.getName() + "'s" << " health: " << mech1.getHealth() << std::endl;
        if (mech1.isDestroyed()) { 
            std::cout << mech1.getName() << " has been destroyed!" << std::endl;
            break;
        }
        rounds++;
    }
}

int main() {
    Mech Inex(150, "Inexorable");
    Mech Scrap(50, "Scrapper");
    Weapon Bs("Beamsword", 10, 25);
    Weapon Br("Beamrifle", 1, 10);
    std::random_device rd;
    std::default_random_engine generator(rd());
    int gauntlet_length = 0;
    while (!Inex.isDestroyed()) {
        std::cout << std::string(20, '*') << std::endl;
        combat(Inex, Scrap, Bs, Br, generator);
    if (Inex.isDestroyed()) {
        break;
    }
    gauntlet_length++;
    }
    std::cout << Inex.getName() << ".... Has been destroyed..." << std::endl;
    std::cout << "He left " << gauntlet_length << " enemies in his wake." << std::endl;
    std::cout << "He fell valiantly against the " << gauntlet_length+1 << "th enemy." << std::endl;
    return 0;
}