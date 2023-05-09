// This program calculates compound interest
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    // gets annual interest rate
    cout << "Enter your annual interest rate: " << endl;
    float interest_rate = 0, times_compounded = 0, principle = 0, interest = 0, final_balance = 0;
    cin >> interest_rate;

    // gets amount of times the interest is compounded
    cout << "Enter the amount of times in the interest is compounded: " << endl;
    cin >> times_compounded;

    // gets the principle
    cout << "Enter your principle: " << endl;
    cin >> principle;

    // displays the data the user entered along with the interest they will earn.
    cout << "Interest Rate: " << interest_rate << "%" << endl;
    cout << "Times Compounded: " << times_compounded << endl;
    cout << "Principle:     $" << principle << endl;
    cout << "Interest:      $" << setprecision(4) << (principle * pow(1 + (interest_rate * 0.01)/(times_compounded), times_compounded) - 1000) << endl;
    cout << "Final Balance: $" << setprecision(6) << principle * pow(1 + (interest_rate * 0.01)/(times_compounded), times_compounded) << endl;
    return 0;
}