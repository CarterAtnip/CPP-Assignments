// Carter Atnip
// Created on 5/10/2023
// accounts for inventory of automobiles

#include <iostream>
#include <string>
#include <new>

class Automobile {
private:
    std::string model; // stores the model of the automobile
    int year{}; // stores the year of the automobile
    float mileage{}; // stores the mileage of the automobile

public:
    Automobile() = default; // default constructor

    // parameterized constructor that initializes the class members listed above, 1 int , 1 floar, 1 string
    Automobile(std::string &mod, int yr, float mlg) {
        model = mod;
        year = yr;
        mileage = mlg;
    }
    // setters for the private members of the class, they go unused here
    void set_model(std::string &mod) {model = mod;}
    void set_year(int yr) {year = yr;}
    void set_mileage(float mlg) {mileage = mlg;}

    // getters for the private members of the class
    std::string get_model() {return model;}
    int get_year() {return year;}
    float get_mileage() {return mileage;}

    // function to display the automobile's details
    void displayAuto() {
        std::cout << "Year: "    << get_year()
                  << " Model: "     << get_model()
                  << ", Mileage: " << get_mileage()
                                   << std::endl;
    };

    // destructor for the class
    ~Automobile() {
        // display a message indicating that the object has been destroyed
        if (year == 0){
            std::cout << "Automobile class destructor: Nothing to destroy, The inventory is empty!" << std::endl;
        } else {
            std::cout << "Automobile class destructor:";
            std::cout << " The " << get_year() << " "
                      << get_model() << " with "
                      << get_mileage() << " miles has been deleted."
                      << std::endl;
        }
    }
};

class Inventory {
private:
    int count; // stores the number of automobiles in the inventory
    int maxCount; // stores the maximum capacity of the inventory
    Automobile *autoPtr; // a pointer to an array of Automobile objects
    friend class Automobile;  // to access private members of the Automobile class

public:
    Inventory() {
        count = 0;
        maxCount = 10;
        autoPtr = nullptr;
    }
// default constructor that sets count and maxCount to 0 and autoPtr to null
    Inventory(int max) {
        count = 0;
        maxCount = max;
        autoPtr = new Automobile[max];
    }
    // function to add an Automobile object to the inventory, accepts 1 automobile param
    void addAutomobile(Automobile &car) {
        if (count >= maxCount) {
            std::cout << "The inventory is full!" << std::endl;
        } else {
            autoPtr[count] = car;
            count++;
        }
    }
    // function to display the content of the inventory
    void displayInventory() {
        if (count == 0){std::cout << "The inventory is empty!" << std::endl;}

        for (int i = 0; i < count; ++i) {
            std::cout << "Car " << i + 1 << ": ";
            autoPtr[i].displayAuto();
        }

    }
    // compares mileage accepts 1 float param, returns nothing
    void mileageComparer(float m) {
        if (count == 0) {
            std::cout << "The inventory is empty!" << std::endl;
        } else {
            std::cout << "Displaying vehicles below " << m << " miles." << std::endl;

            for (int i = 0; i < count; ++i) {
                if (autoPtr[i].get_mileage() < m) {
                    autoPtr[i].displayAuto();
                }
            }
        }
    }
    // deletes array when done returns nothing no params
    void memory_cleaner() {delete[] autoPtr;}
    //destructor that displays to console when object is deleted
    ~Inventory(){
        std::cout << "Inventory class destructor called." << std::endl;
    }

};


//Prototypes
void addNewAuto(Inventory &inv);
void searchAuto(Inventory inv);
// main function

int main() {
    int size; // stores the size of the inventory

    while (true) {
        std::cout << "How large is the inventory capacity?" << std::endl;
        std::cin >> size; // stores the size of the inventory

        if (size >= 0) {
            break;
        } else {
            std::cout << "Error no negative numbers, please try again." << std::endl;
        }
    }

        Inventory inventory(size); // creates inventory instance
        int input; //user input init

        do {
            std::cout << "Choose an option from the menu:\n"
                      << "1: Add an automobile to the inventory\n"
                      << "2: Display the content of the inventory\n"
                      << "3: Display the automobiles below certain mileage\n"
                      << "4: Exit\n";

                      std::cin >> input; // stores user input

            switch (input) {
                case 1:
                    addNewAuto(inventory); // calls addNewAuto function
                    break;

                case 2:
                    inventory.displayInventory();
                    break;

                case 3:
                    searchAuto(inventory);
                    break;

                case 4:
                    std::cout << "Goodbye!" << std::endl;
                    break;

                default:
                    std::cout << "Invalid input, please try again"  << std::endl;
                    break;
            }
        } while (input != 4);

        inventory.memory_cleaner();
        return 0;
}

void addNewAuto(Inventory &inv) {
    std::string model;
    int year{};
    float mileage{};

    std::cout << "Please enter the model: " << std::endl;
    std::cin >> model;

    while (true) {
        std::cout << "Please enter the year: " << std::endl;
        std::cin >> year;

        if (year > 1671) {
            break;
        } else {
            std::cout << "Automobiles were not around yet, please try again." << std::endl;
        }
    }

    while (true) {
        std::cout << "Please enter the mileage: " << std::endl;
        std::cin >> mileage;

        if (mileage >= 0) {
            break;
        } else {
            std::cout << "Mileage must be positive, please try again." << std::endl;
        }
    }

    Automobile car(model, year, mileage);
    inv.addAutomobile(car);
}

void searchAuto(Inventory inv) {
    float mileage{};

    while (true) {
        std::cout << "Please enter the mileage: " << std::endl;
        std::cin >> mileage;

        if (mileage >= 0) {
            break;
        } else {
            std::cout << "Mileage must be positive, please try again.";
        }
    }

    inv.mileageComparer(mileage);
}