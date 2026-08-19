#ifndef WEAPON_H
#define WEAPON_H
#include <string>

class Weapon {
    private:
        // Name of the weapon
        std::string name;
        // Range of damage a weapon does
        int minDamage;
        int maxDamage;
    public:
        /**
         * Default constructor of a weapon
         */
        Weapon();

        /**
         * Getter for name
         * @return name of weapon
         */
        std::string getName();

        /**
         * Getter for minimum damage value
         * @return value of minimum damage the weapon does
         */
        int getMinDamage();

        /**
         * Getter for max damage value
         * @return value of maximum damage does
         */
        int getMaxDamage();

        /**
         * Parameterized constructor for weapon
         */
        Weapon(std::string givenName, int minDamage, int maxDamage);
};

#endif //WEAPON_H