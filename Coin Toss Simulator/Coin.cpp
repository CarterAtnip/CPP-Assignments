// Carter Atnip
// This program flips a coin 20 times displays the orientation, and counts the amount of times it lands on one face.
//

#include <cstdlib>
#include <string>
#include <iostream>
#include <time.h>



class Coin { // makes a coin object
    std::string side_up; // stores the orientation of the coin

public:
    explicit Coin() { // constructor that gets the initial orientation and seeds rng
        srand(time(nullptr)); // seeds the rng
        toss();
    }

    void toss() { // uses rng to flip the coin
        int coin = rand() % 2; // stores the random number
        if (coin == 1) { // determines the orientation based if the random number is even or odd
            side_up = "heads";
        } else {
            side_up = "tails";
        }
    }

    std::string get_side_up() { // returns the orientation of the coin
        return side_up;
    }
};

int main() { // main
    Coin coin_obj; // creates an instance of the Coin class
    std::cout << "Beginning Orientation: " << coin_obj.get_side_up() << std::endl;

    int heads_count = 0; // stores how many times a coin lands on heads
    int tails_count = 0; // stores how many times a coin lands on tails

    for (int i = 1; i < 21; ++i) { // loops 20 times
        coin_obj.toss();
        std::cout << "Toss " << i << ": " << coin_obj.get_side_up() << std::endl;

        if (coin_obj.get_side_up() == "heads"){
            ++heads_count;
        } else {
            ++tails_count;
        }
    }

    std::cout << "Total Heads: " << heads_count << std::endl;
    std::cout << "Total Tails: " << tails_count;

    return 0;
}