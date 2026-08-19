#include "weapon.h"

// Default constructor for weapon
Weapon::Weapon() {
    name = "Unknown";
    minDamage = 1;
    maxDamage = 10;
}

// Parameterized constructor for weapon
Weapon::Weapon(std::string givenName, int givenMinDamage, int givenMaxDamage) {
    name = givenName;
    minDamage = givenMinDamage;
    maxDamage = givenMaxDamage;
}

// Getter for weapon name
std::string Weapon::getName() {
    return name;
}

// Getter for minimum weapon damage amount
int Weapon::getMinDamage() {
    return minDamage;
}

// Getter for maximum weapon damage amount
int Weapon::getMaxDamage() {
    return maxDamage;
}



