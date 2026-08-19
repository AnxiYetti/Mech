// #include <random>
// #include <iostream>

// int randomNumber(std::default_random_engine& gen) {
//     int diceroll = 0;
//     std::uniform_int_distribution<int> distribution(1,10);
//     int dice_roll = distribution(gen);
//     return dice_roll;
// }

// int main() {
//     std::random_device rd; // seed
//     std::default_random_engine generator(rd()); // it has seed!
//     std::cout << "Random number: " << randomNumber(generator) << std::endl;
//     std::cout << "Random number: " << randomNumber(generator) << std::endl;
//     return 0;
// }