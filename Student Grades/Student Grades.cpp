// Creates and stores student info
// Created by Carter Atnip on 4/16/2023

#include <iostream>
#include <vector>
#include <string>

class Student { // creates an object for students and stores their name, age, and gpa
private:
  std::string name; // stores the students name
  int age; // stores th students age
  float gpa; // stores the students gpa

public:
    Student() = default; // default constructor


    Student(std::string n, int a, float grade) { // constructor that sets the student name, age, and gpa
        name = n; // sets name
        age = a; // sets age
        gpa = grade; // sets gpa
    }

    //setters
    void set_name(std::string n) { // gets name, 1 string parameter, returns nothing
        name = n; // manually setting name
    }


    void set_age(int a) { // sets age, 1 int parameter, returns nothing
        age = a; // manually setting age
    }


    void set_gpa(float grade) { // sets gpa, 1 float parameter, returns nothing
        gpa = grade; // manually setting grade
    }

    //getters
    std::string get_name() { // gets name, no parameters, returns string
        return name; // gets name and returns it
    }


    int get_age() { // gets age, no parameters, returns age
        return age; // gets age and returns it
    }


    float get_gpa() { // gets gpa, no parameters, returns age
        return gpa; // gets gpa and returns it
    }


    void DisplayStudent() { // prints the students info no parameters, returns nothing
        std::cout << "Name: " << name << std::endl;
        std::cout << "Age: " << age << std::endl;
        std::cout << "GPA: " << gpa << std::endl;
    }


    ~Student() { // destructor that displays when an object is destroyed
        std::cout << "Object for student " << get_name() << " deleted." << std::endl;
    }
};


void acceptStudentInfo(std::vector<Student> &studentArr) { // takes user input and changes elements attributes in array
                                                            // returns nothing, 1 vector param
    std::string name; //stores students name
    int age; //stores students age
    float gpa; //stores students gpa

    for (int i = 0; i < studentArr.size(); ++i) { // loops through student array
        std::cout << "Enter student " << i + 1 << "'s name: " << std::endl; // prompts user to enter student name
        std::cin >> name; // stores users input

        std::cout << "Enter student " << i + 1 << "'s age: " << std::endl; // prompts user to enter student age
        std::cin >> age; // stores user input

        std::cout << "Enter student " << i + 1 << "'s GPA: " << std::endl; // prompts user to enter student gpa
        std::cin >> gpa; // stores user input

        Student student(name, age, gpa); // creates student object with attributes user entered

        studentArr[i] = student; // sets element in array to the object created above
    }
}


void displayStudentInfo(std::vector<Student> studentArr) { // displays student info in array, returns nothing, 1 vector parameter
    for (int i = 0; i < studentArr.size(); ++i) { // loops through student array
        studentArr[i].DisplayStudent(); // displays item at index specified, call DisplayStudent function
        std::cout << "----------------" << std::endl; // outputs dividing line
    }
}


void sortStudentGPA(std::vector<Student> &studentArr) { // sorts student array by GPA using bubble sort, returns nothing, accepts 1 vector parameter
    int i = 0; // indexer1
    int j = 1; // indexer2
    int exit_check = 0; // check if list is sorter

    while (true) { // loops until told to break

        if (studentArr[i].get_gpa() > studentArr[j].get_gpa()) { // checks if elements in the array are greater than onr another
            std::swap(studentArr[i], studentArr[j]); // swaps elements in array
            exit_check = 0; // sets exit check to zero because since this block executed, the array is not sorted
        } else {
            exit_check++; // increments exit check since no swap was done
            if (exit_check == studentArr.size() - 1) { // checks if exit check has been incremented enough to exit
                std::cout << "Bubble sort complete." << std::endl; // tells user bubble sort was done
                break; // breaks loop
            }
        }

        if (j == studentArr.size() - 1) { // checks if indexes are larger than the array and if they are it resets them
            i = 0; // resets indexer1
            j = 1; // resets indexer2
            exit_check = 0; // resets exit check

        } else { // if the indexers are not larger, then it increments them
            i++; // increments indexer1
            j++; // increments indexer2
        }
    }
}


int main() { // main function
    std::cout << "How many students do you have?" << std::endl; // prompts user to enter how many students they have

    int quantity; // stores how many students the user has
    std::cin >> quantity; // stores quantity user enters

    std::vector<Student> studentArr(quantity); // creates a vector of Student objects based on the amount of students enter by the user

    acceptStudentInfo(studentArr); // calls acceptStudentInfo function
    displayStudentInfo(studentArr); // calls displayStudentInfo function
    sortStudentGPA(studentArr); // calls sortStudentGPA function
    displayStudentInfo(studentArr); // calls displayStudentInfo function

    return 0;
}