// Carter Atnip
// Created on 3/28/2023
// calculates survey data based on college student movie attendance

#include <iostream>
#include <new>
#include <string>

class MovieAttendance {
private:
    int amount_surveyed; // stores the number of students surveyed
    int *student_array = new int[amount_surveyed]; // dynamically allocates array of size based on the amount surveyed
public:
    MovieAttendance() { // constructor requires no params, sets amount surveyed
        std::cout << "How many students were surveyed?" << std::endl; // prompts user to enter amount
        int quantity = 0; // initializes the amount
        std::cin >> quantity; // sets quantity to amount user entered

        while (quantity < 0) { // validates input is positive
            std::cout << "Error, input must be positive, please try again." << std::endl; // prompts user to retype
            std::cout << "How many students were surveyed?" << std::endl; // repromputs user
            std::cin >> quantity; // stores user input
        }
        amount_surveyed = quantity; // sets amount_surveyed to the same as the user input quantity
    }

    void movie_data_setter() { // sets data for each item in array created, no params, no return
        for (int i = 0; i < amount_surveyed; ++i) { // loops until array is full
            std::cout << "How many movies did student " << i +1 << " watch?" << std::endl; // asks user to enter quantity

            int quantity; // initilizes quantity
            std::cin >> quantity; // stores user input

            while (quantity < 0) { // loops until quantity is set to a positive number
                std::cout << "Error, input must be positive, please try again." << std::endl; // prompts user to reenter input
                std::cout << "How many movies did student " << i +1 << " watch?" << std::endl; // prompts user again
                std::cin >> quantity; // stores user input
            }

            student_array[i] = quantity; // sets item in array to user input
        }

        int i = 0; // indexer1
        int j = 1; // indexer2
        int exit_check = 0; // check if list is sorter

        while (true) { // loops until told to break

            if (student_array[i] > student_array[j]) { // checks if elements in the array are greater than onr another
                std::swap(student_array[i], student_array[j]); // swaps elements in array
                exit_check = 0; // sets exit check to zero because since this block executed, the array is not sorted
            } else {
                exit_check++; // increments exit check since no swap was done
                if (exit_check == amount_surveyed - 1) { // checks if exit check has been incremented enough to exit
                    break; // breaks loop
                }
            }

            if (j == amount_surveyed - 1) { // checks if indexes are larger than the array and if they are it resets them
                i = 0; // resets indexer1
                j = 1; // resets indexer2
                exit_check = 0; // resets exit check

            } else { // if the indexers are not larger, then it increments them
                i++; // increments indexer1
                j++; // increments indexer2
            }
        }
    }

    float average() { // calculates average, no params, returns float
        float avg = 0; // sets avg equal to zero for default

        for (int i = 0; i < amount_surveyed; ++i) { // loops until all numbers are added
            avg += student_array[i]; // stores all numbers in avg
        }

        return avg / amount_surveyed; // returns ave variable divided by amount of items in array
    }

    float median() { // calculates median, no params, returns float
        float med = 0; // default seds med to 0
        int half = amount_surveyed/2; //cuts the amount of peope surveyed in half

        if (amount_surveyed % 2 == 0) { // checks if amount serveyed is even
            med = (student_array[half] + student_array[half - 1]); // gets the two middle of the road numbers and adds them
            med /= 2; // divides med by 2 to get the average of the 2 middle numbers
        } else { // if the amount surveyed is odd it gets the number in the middle
            med = student_array[half]; // takes half as index and grabs number there
        }
        return med; // returns med
    }

    std::string mode() { // returns string, no params, gets the mode of the data set
        int **mode_array = new int *[amount_surveyed / 2]; // create 2d array of ints
        for (int i = 0; i < amount_surveyed / 2; ++i) { // sets each sub array to have 2 entries
            mode_array[i] = new int[2]; //sets each sub array to have 2 entries
        }

        for (int i = 0; i < amount_surveyed / 2; ++i) { //sets every entry in mode array to -1
            mode_array[i][0] = -1; //sets every entry in mode array to -1
            mode_array[i][1] = -1; //sets every entry in mode array to -1
        }

        for (int i = 0; i < amount_surveyed; ++i) { // determines if there are any common entries in the data
            if (student_array[i] == student_array[i + 1]) { // checks if two entries are the same number
                mode_array[(i + 1) / 2][0] = student_array[i]; // changes entry at index 0 to the number that there is a duplicate of
                if (mode_array[(i + 1) / 2][1] == -1) { // checks if the entry already occurred as a mode in the array, if it hasn't it creates new entry
                    mode_array[(i + 1) / 2][1] = 2; // sets entry to 2 since there are 2 identical data entries
                } else { // if the item already exists it increments the second element of the array
                    mode_array[(i + 1) / 2][1]++; // if the item already exists it increments the second element of the array
                }
            }
        }

        int largest = -2; // sets largest to -2 since it cannot be used anywhere by the user

        for (int i = 0; i < amount_surveyed / 2; ++i) { //detmerines which entry occurs the most in the mode array
            if (mode_array[i][1] >= 2 && mode_array[i][1] > largest) { //detmerines which entry occurs the most in the mode array
                largest = mode_array[i][1]; // sets largest equal to the quantity of times the most commen entry occured
            }
        }

        std::string mode_string; // creates string that will be returned

        for (int i = 0; i < amount_surveyed / 2; ++i) { // adds all modes if there are multiple to the string
            if (mode_array[i][1] == largest) { // if there is a mode it adds it to the string
                mode_string += std::to_string(mode_array[i][0]) + ", "; // adds mode to the string after casting from type int
            }
        }

        if (mode_string.empty()) { // checks if there is a mode, if not sets the string to none
            mode_string = "none"; // sets string to none
        }

        for(int i = 0; i < amount_surveyed/2; ++i) { // loops through to delete every sub array
            delete[] mode_array[i]; // deletes sub array
        }
        delete[] mode_array; // deletes main array after sub array is deleted

        return mode_string; // returns mode string
    }
    void formatter() { // returns nothing, has no params, calls other function and formats data
        std::cout << "Average: " << average() << std::endl; // calls average function and displays it
        std::cout << "Median: " << median() << std::endl; // calls median function and displays it
        std::cout << "Mode(s): " << mode() << std::endl; // calls mode function and displays it
    }
    ~MovieAttendance() { // destructor deletes dynamically allocated items
        delete[] student_array; // deletes student array
    }
};

int main() { // main
    MovieAttendance survey; //creates Movie attendance object called survey
    survey.movie_data_setter(); // adds data to object
    survey.formatter(); // formats data in object
    return 1; // returns 1
}