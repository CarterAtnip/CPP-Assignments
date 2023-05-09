// This program calculates the average and total rainfall during specified months of the year
// Carter Atnip
#include <iostream>
#include <fstream>
#include <string>


using namespace std;

int main(){
    ifstream rainfall_list; // initalizes txt file opening
    rainfall_list.open("rainfall.txt"); // opens txt

    if (rainfall_list.is_open()){ // ensures file is open
       string start_month; // initializes variable
       string end_month; // initializes variable

       rainfall_list >> start_month; //reads first line of txt and stores it a string
       rainfall_list >> end_month; // reads second line of txt and stores it a string

       double total = 0; // stores total rain
       double i = 0; // stores value from txt and adds it to total
       int loopcount = 0; // counts amount of times the while loop repeats

       while (rainfall_list >> i){
           total += i; // adds i to total
           loopcount++; // increments loop count

        }
       cout << "During the months of " << start_month << "-" << end_month << " the total rainfall was " << total
            << " inches and the average rainfall was " << total/loopcount << " inches.";
       rainfall_list.close(); // closes txt when finished with it

    }

	return 0;
    // end of program
}
