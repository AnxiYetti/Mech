#include "mech.h"
#include "weapon.h"
#include <string>

// Default constructor: set the health to 100.
Mech::Mech() {
    health = 100;
    frame = "Unkown Frame";
}

// Parameterized constructor: set the health to user input.
Mech::Mech(int newHealth, std::string givenName){
    // validate user input. (No neg, or char).
    if (newHealth > 100) {
        health = newHealth;
    } else {
        health = 100;
    }
    frame = givenName;
}

bool Mech::isDestroyed() {
    return health == 0;
}

int Mech::getHealth() {
    return health;
}

std::string Mech::getName() {
    return frame;
}

void Mech::dealDamage(Mech& target, int dmg){
    target.takeDamage(dmg);
}

void Mech::takeDamage(int dmg) {
    health -= dmg;
    if (health < 0) {
        health = 0;
    }
}