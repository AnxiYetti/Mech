#include <iostream>
#include <string>
#include <random>
#include "mech.h"
#include "weapon.h"

int randomDmgNumber(std::default_random_engine& gen, Weapon& weapon) {
    std::uniform_int_distribution<int> distribution(weapon.getMinDamage(), weapon.getMaxDamage()); // needs min and max values of weapon
    int rngDamage = distribution(gen);
    return rngDamage;
}

void combat(Mech& mech1, Mech mech2, Weapon& weapon1, Weapon& weapon2, std::default_random_engine& gen) {
    int i = 0;
    bool activeCombat = true;
    while (!mech2.isDestroyed()) {
        std::cout << "Round " << i+1 << "!" << '\n'
                  << "Inexorable swings beamsword at the Bum!" << '\n';
        int mech1rngDmg = randomDmgNumber(gen, weapon1);
        std::cout << "Inexorable dealt " << mech1rngDmg << " damage!" << std::endl; 
        mech1.dealDamage(mech2, mech1rngDmg);
        std::cout << "Bum's health: " << mech2.getHealth() << '\n';
        if (mech2.isDestroyed()) {
            std::cout << "Bum has been destroyed!" << std::endl;
            break;
        }
        std::cout << "Bum responds with a Beamrifle!" << '\n';
        int mech2RngDmg = randomDmgNumber(gen, weapon2);
        std::cout << "Bum dealt " << mech2RngDmg << " damage!" << std::endl;
        mech2.dealDamage(mech1, mech2RngDmg); // Needs nothing now! lol
        std::cout << "Inexorable's health: " << mech1.getHealth() << '\n';
        if (mech1.isDestroyed()) { 
            std::cout << "Inexorable has been destroyed!" << std::endl;
            break;
        }
        i++;
    }
}

int main() {
    Mech Inex(150, "Inexorable");
    Mech Bum(50, "Bum");
    Weapon Bs("Beamsword", 1, 25);
    Weapon Br("Beamrifle", 1, 10);
    std::random_device rd;
    std::default_random_engine generator(rd());
    int gauntlet_length = 0;
    while (!Inex.isDestroyed()) {
    std::cout << std::string(20, '*') << std::endl;
    combat(Inex, Bum, Bs, Br, generator);
    gauntlet_length++;
    }
    std::cout << "Inexorable.... Has been destroyed..." << std::endl;
    std::cout << "He stood valiantly against " << gauntlet_length << " enemies." << std::endl;
    return 0;
}