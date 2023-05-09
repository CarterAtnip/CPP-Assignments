// Carter Atnip
// Created on 3/28/2023
// Calculates how much each employee is owed based on how much they worked and their hourly rate

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <new>


class PayRoll { //Payroll class
private:
    float hourly_rate; // stores the employees hourly rate
    float hours_worked; // stores the employees hours worked

public:
    PayRoll() = default; // default constructor

    void set_hourly_rate(float rate) { // sets the hourly rate
        hourly_rate = rate;            // returns nothing
    }                                  // accepts one float parameter

    void set_hours_worked(float worked) { // sets the hours worked for the week
        hours_worked = worked;            // returns nothing
    }                                     // accepts one float parameter


    float get_hourly_rate() { // gets the hourly rate
        return hourly_rate;   // returns a float
    }                         // accepts no parameters

    float get_hours_worked() { // gets the hours worked
        return hours_worked;   // returns a float
    }                          // accepts no parameters

    float get_gross_pay() {                // gets the gross pay
        return hours_worked * hourly_rate; // returns a float
    }                                      // accepts no parameters
};


int main() { //main function
    std::ifstream data ("payrolldata.txt"); //opens payrolldata.txt file with input data
    std::string data_read; // initializes the data_read variable
    std::vector<std::vector<float>> payroll_array; //initializes a 2d vector of floats

    while (data >> data_read) { // loops until file is done being read and stores the input in data_read
        std::vector<float> ordered_pair; // initializes a vector of floats

        ordered_pair.push_back(std::stof(data_read)); // stores the value of data_read in a the float vector
        data >> data_read; // reads the next text entry in payrolldata.txt
        ordered_pair.push_back(std::stof(data_read)); // stores the value of data_read in a the float vector

        payroll_array.push_back(ordered_pair); // stores the ordered pair array in the 2d vector
    }
    data.close(); // closes payroll.txt

    int number_of_employees = payroll_array.size(); // stores the size of the vector
    auto *employees = new PayRoll[number_of_employees](); // creates a pointer array that stores a quantity of payroll
                                                          // objects, the size is determined by the size of the
                                                          // payroll_array vector
    for (int i = 0; i < number_of_employees; ++i) { // loops through the payroll array to set the employees attributes
        employees[i].set_hourly_rate(payroll_array[i][1]); // sets the hourly rate of and employee
        employees[i].set_hours_worked(payroll_array[i][0]); // sets the hours worked of an employee

        std::cout << "\nEmployee: " << i + 1 //displays each employees hours and pay rate
                  << "\nHourly Rate: "<< employees[i].get_hourly_rate()
                  << "\nHours Worked: " << employees[i].get_hours_worked()
                  << "\nGross Pay: $" << employees[i].get_gross_pay()
                  << std::endl;
    }

    return 0;
}
