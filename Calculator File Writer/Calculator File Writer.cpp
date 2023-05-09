// Carter Atnip
// this program gives the user a menu and options to choose from such as calculators and file readers/writers

#include <iostream>
#include <string>
#include <fstream>
#include <istream>

using namespace std;

// Prototypes
void calcAverage(); // calculates average returns nothing, has no parameters

int calcMinimum(); // calculates minimum number returns integer, has no parameters

void calcMaximum(); // calculates largest number returns nothing, has no parameters

void writeFile(string fileName); // creates and writes to a txt file has one string parameter, returns nothing

void readFile(); // reads from a text file returns nothing, has no parameters


int main() { // main
    cout << "Please select an option from the menu Below or enter 6 to exit:" << endl;

    int selection = 0; // initilizes selector for user
    string fileName; // initializes variable for file writer since vars cannot be declared in switch case
    int minimum; // initilizes minimum number variable since vars cannot be used in switch case

    while (selection != 6) { // loop exits if user enters 6
        cout << endl
             << "1: Average Calculator" << endl
             << "2: Minimum Calculator" << endl
             << "3: Maximum Calculator" << endl
             << "4: Text File Writer" << endl
             << "5: Text File Reader" << endl
             << "6: Exit" << endl;

        cin >> selection; // stores user input to select from menu


        switch (selection) { // chooses what user selected
            case 1:
                calcAverage();
                break;

            case 2:
                minimum = calcMinimum();
                cout << "The largest number of the set is: " << minimum << endl;
                break;

            case 3:
                calcMaximum();
                break;

            case 4:
                cout << "Please enter what you would like the file to be called: " << endl;
                cin >> fileName; // stores file name to be passed to file creation function

                writeFile(fileName);
                break;

            case 5:
                readFile();
                break;

            case 6:
                cout << "Goodbye!";
                break;

            default:
                cout << "Error, invalid entry. Please choose a different option" << endl;
                break;

        }
    }

    return 0;
}


void calcAverage() { // calculates the average of the numbers passed by the user, returns none, no parameters
    cout << "Enter the quantity of numbers you will be average from: " << endl;

    int numQuantity = 0; // initilizes the amount of numbers the user will be averaging

    do {
        cin >> numQuantity; // stores the amount of numbers the user will be averaging

        if (numQuantity < 0) { // check to make sure user entered a positive value
            cout << "Please enter a positive value: " << endl;
        }
    } while (numQuantity < 0); // loops again if the number the user entered is not positive

    int number = 0; // initializes the number variable user to store the numbers the user passes
    double average = 0; // initilizes the average variable which all the numbers are added to

    for (int i = 0; i < numQuantity; ++i) {
        cout << "Number " << i + 1 << ": " << endl;
        cin >> number; // stores the number the user enters
        average += number; // adds the number the user entered
    }
    cout << "The average of these " << numQuantity << " number(s) is: " << average / numQuantity << endl;
}


int calcMinimum() { // calculates the minimum number the user enters and exits if they enter -99, returns int,
                    // no parameters
    cout << "Enter as many integers as you like to determine the smallest one. Or enter -99 to exit." << endl;

    int minimum; // initlizes minimum variable which stores user input
    cin >> minimum; // stores the users input
    int comparer = minimum; // sets the comparision variable equal to minimum for comparison

    while (minimum != -99) { // ends the loop if user enters -99
        cout << "Enter -99 to stop, or enter another number: " << endl;
        cin >> minimum; // stores the users minimum input

        if (minimum < comparer && minimum != -99) { // determines if the number the user just entered is
                                                    // smaller than the prior one
            comparer = minimum;
        }
    }

    return comparer; // returns the integer that was the smallest of the users entries
}


void calcMaximum() {// calculates the maximum number the user enters and exits if they enter 99, returns none,
                    // no parameters
    cout << "Enter as many integers as you like to determine the largest one. Or enter 99 to exit." << endl;

    int maximum; // initlizes maximum variable which stores user input
    cin >> maximum; // stores the users input
    int comparer = maximum; // sets the comparision variable equal to maximum for comparison

    while (maximum != 99) { // ends the loop if user enters 99
        cout << "Enter 99 to stop, or enter another number: " << endl;
        cin >> maximum; // stores the users maximum input

        if (maximum > comparer && maximum != 99) {  // determines if the number the user just entered is
                                                    // larger than the prior one
            comparer = maximum;
        }
    }

    cout << "The largest number of the set is: " << comparer << endl;
}

void writeFile(string fileName) { //creates and writes to file user created, returns nothing, has string parameter
    ofstream outfile(fileName); //opens file

    cout << "File " << fileName << " created, please enter what should be written to the file or type 'NULL' to exit."
         << endl;

    string line = "";
    int loopcheck = 1; // makes sure the file does not output a blank line at the begginng of the txt

    while (line != "NULL") { // ends loop if user enters null
        getline(cin, line); // gets the whole line of user input
        if (line == "") { // makes sure a blank line is not output at the start of the txt file
            loopcheck = 0; // sets loop count to 0 to ensure the loop has only completed one loop

        } else if (line != "NULL" && loopcheck == 0) { // makes sure the loop is on its second go around before
                                                        // if statement trigges, checks if user enters null
            outfile << line << endl;
            cout << "Creating next line..." << endl;

        } else {
            cout << "File is complete." << endl;
            outfile.close(); // closes file when done
        }
    }
}

void readFile() { // returns nothing, no parameters
    while (true) { // continues until break condition is met
        cout << "Please enter the name of the file you would like to read from: " << endl;

        string fileName; // initializes the file name variable
        cin >> fileName; // stores the name of the file the user is trying to open

        ifstream myFile; // initilizes read only file variable
        myFile.open(fileName); // attempts to open file

        if (!myFile.is_open()) { // if file opening is unsuccessful, it prompts user to enter file name again
            cout << "Error, file does not exist. Restarting..." << endl;

        } else { // when file name is determined to be valud this executes
            cout << "The file says:\n" << endl;
            cout << "-------------------------" << endl;
            string line; // stores line of each file
            while (getline (myFile,line)) { // prints line of file
                cout << line << endl;
            }
            cout << "-------------------------" << endl;
            myFile.close(); // closes file
            break;
        }
    }
}