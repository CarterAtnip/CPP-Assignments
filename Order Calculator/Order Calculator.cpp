// Carter Atnip
// This program gathers how many wire spools are in stock and calculates the selling price, inventory, and backlog
#include <iostream>
using namespace std;

void inventory_getter(int& quantity_ordered, int& stock, double &additional_charges); //function prototype
void transaction_processor(int quantity_ordered, int stock, double additional_charges=10.00); //function prototype

int main(){
    int quantity_ordered; // stores the amount of spools someone ordered
    int stock; // stores the amount of spools that are in stock
    double additional_charges; // stores the potential additional charges

    inventory_getter(quantity_ordered, stock, additional_charges);
    transaction_processor(quantity_ordered, stock, additional_charges);

    return 0;
}
// Inventory_getter stores the users input and in the variables pass to it and determines if
// there are additional charges
void inventory_getter(int& quantity_ordered, int& stock, double &additional_charges) {
    cout << "Enter the amount of spools ordered:" << endl;
    cin >> quantity_ordered; // stores user input

    cout << "Enter the amount of spools currently in stock:" << endl;
    cin >> stock; // stores user input

    char additional_charges_check;
    cout << "Are there any additional charges? Y/N" << endl;
    cin >> additional_charges_check; // stores user input

    if (additional_charges_check == 'Y') {
        cout << "How much is the additional charge in total?" << endl;
        cin >> additional_charges; // stores user input
    } else {
        additional_charges = 10.0; // if there are no additional charges, defaults the shipping to 10$
    }
}
// transaction_processor takes the values passed to it and calculates the inventory, backlog, and price of sales
// then it displays it
void transaction_processor(int quantity_ordered, int stock, double additional_charges) {
    int backorder = 0; // stores the amount of product on back order

    if (quantity_ordered > stock) {
        backorder = quantity_ordered - stock; // determines if there is any back order
        quantity_ordered = stock; // sets the quantity order to the value of stock if there is more ordered than stock
    }

    cout << "Spools ready to ship:                                 " << quantity_ordered << endl;
    cout << "Spools on back order:                                 " << backorder << endl;
    cout << "Selling price on spools ready to ship:                " << quantity_ordered * 100 << "$" << endl;
    cout << "Shipping and handling charge on spools ready to ship: " << quantity_ordered * additional_charges << "$"
                                                                     << endl;
    cout << "Total price on order ready to ship:                   " << (quantity_ordered * additional_charges) +
                                                                        (quantity_ordered * 100) << "$" << endl;

}

