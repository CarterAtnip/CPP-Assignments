// compares and displays bubble sort and selection sort
// Created by Carter Atnip on 3/29/2023

// include necessary libraries
#include <iostream> // for input/output streams
#include <new> // for dynamic memory allocation
#include <time.h> // for time functions
#include <cstdlib> // for random number generation
#include <array> // for array container

class SortingAlgorithms {
private:
    int array_length = 0; // length of array to be sorted

public:
    SortingAlgorithms(int length) { // constructor to initialize array length
        array_length = length;
    }

private:
    int *number_array = new int[array_length]; // dynamic allocation of memory for array

public:
    void randomize() { // function to fill array with random numbers
        srand(time(nullptr)); // seed random number generator with current time
        for (int i = 0; i < array_length; ++i) {
            int random = rand(); // generate random number
            number_array[i] = random; // store random number in array
        }
    }

    void get_array() { // function to print the contents of the array
        std::cout << '[';

        for (int i = 0; i < array_length; ++i) {
            std::cout << number_array[i] << ","; // print each element of array
        }

        std::cout << ']' << std::endl; // print closing bracket and move to new line
    }

    void bubble_sort() { // function to perform bubble sort algorithm
        get_array(); // print the initial unsorted array

        int i = 0;
        int j = 1;
        int exit_check = 0;

        while (true) {

            if (number_array[i] > number_array[j]) {
                std::swap(number_array[i], number_array[j]); // swap elements of array
                get_array(); // print the new array after the swap
                exit_check = 0;
            } else {
                exit_check++;

                if (exit_check == array_length - 1) { // if no swaps were made in the last iteration, the array is sorted
                    std::cout << "Bubble sort complete." << std::endl; // print message indicating completion of bubble sort
                    break; // exit loop
                }
            }

            if (j == array_length - 1) { // if we have reached the end of the array, reset the indices
                i = 0;
                j = 1;
                exit_check = 0;

            } else {
                i++;
                j++;
            }
        }
    }

    void selection_sort() { // function to perform selection sort algorithm
        get_array(); // print the initial unsorted array

        int i, j, minimum;

        for(i = 0; i < array_length - 1; i++) {
            minimum = i;

            for(j = i + 1; j < array_length; j++)
                if(number_array[j] < number_array[minimum])
                    minimum = j;

            std::swap(number_array[i], number_array[minimum]); // swap elements of array
            get_array(); // print the new array after the swap
        }
        std::cout << "Selection sort complete."; // print message indicating completion of selection sort
    }

    ~SortingAlgorithms() { // destructor to free up memory
        delete[] number_array;
    }
};

int main() {
    std::cout << "Enter how many random numbers you would like to sort:" << std::endl;
    int quantity;
    std::cin >> quantity;

    SortingAlgorithms bubble_sort_array(quantity); // create object for bubble sort algorithm
    SortingAlgorithms selection_sort_array(quantity); // create object for selection sort algorithm

    bubble_sort_array.randomize();
    selection_sort_array.randomize();

    bubble_sort_array.bubble_sort();
    std::cout << "---------------------------------------------" << std::endl;
    selection_sort_array.selection_sort();

    return 0;
}