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

int main() {
    Mech Inex(150, "Inexorable");
    Mech Bum(50, "Bum");
    Weapon Bs("Beamsword", 1, 25);
    Weapon Br("Beamrifle", 1, 10);
    std::random_device rd;
    std::default_random_engine generator(rd());
    int i = 0;
    bool activeCombat = true;
    while (activeCombat) {
        std::cout << "Round " << i+1 << "!" << '\n'
                  << "Inexorable swings beamsword at the Bum!" << '\n';
        int mech1rngDmg = randomDmgNumber(generator, Bs);
        std::cout << "Inexorable dealt " << mech1rngDmg << " damage!" << std::endl; 
        Inex.dealDamage(Bum, mech1rngDmg);
        std::cout << "Bum's health: " << Bum.getHealth() << '\n';
        if (Bum.isDestroyed()) {
            std::cout << "Bum has been destroyed!" << std::endl;
            activeCombat = false;
            break;
        }
        std::cout << "Bum responds with a Beamrifle!" << '\n';
        int mech2RngDmg = randomDmgNumber(generator, Br);
        std::cout << "Bum dealt " << mech2RngDmg << " damage!" << std::endl;
        Bum.dealDamage(Inex, mech2RngDmg); // Needs nothing now! lol
        std::cout << "Inexorable's health: " << Inex.getHealth() << '\n';
        if (Inex.isDestroyed()) { 
            std::cout << "Inexorable has been destroyed!" << std::endl;
            activeCombat = false;
            break;
        }
        i++;
    }

    return 0;
}