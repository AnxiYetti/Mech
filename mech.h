#ifndef MECH_H
#define MECH_H

#include "weapon.h"
#include <string>

class Mech{
    private:
        // The name of the Mech's frame
        std::string frame;
        // The amount of health which should default to 100 unless specified.
        int health;

    public:
        /**
         * Default constructor: set the health to 100.
         */
        Mech();

        /**
         * Evaluate status of frame.
         * @return T or F dependent on health
         */
        bool isDestroyed();

        /**
         * Getter for health
         * @return health amount
         */
        int getHealth();

        /**
         * Parameterized constructor: set the health to user input.
         */
        Mech(int newHealth, std::string givenName);

        /**
         * Getter for frame name
         * @return frame name
         */
        std::string getName();

        /**
         * Deal damage to a frame
         */
        void dealDamage(Mech& target, int dmg);

        /**
         * Take damage from an attack
         */
        void takeDamage(int dmg);

};

#endif //MECH_H