// This program calculates Time
#include <iostream>

using namespace std;

int main() {
    int seconds = 0;
    cout << "Enter the amount of seconds you wish to convert: \n";
    cin >> seconds;

    cout << "In " << seconds << " seconds there are ";

    int day = 0;
    if(seconds >= 86400) {
        day = seconds / 86400;
        seconds -= (86400 * day);

    }

    int hour = 0;
    if (seconds >= 3600){
        hour = seconds / 3600;
        seconds -= (3600 * hour);
    }

    int minute = 0;
    if (seconds >= 60){
        minute = seconds / 60;
        seconds -= (60 * minute);
    }

    cout << day << " day(s) " << hour << " hour(s) " << minute << " minute(s) and " << seconds << " second(s).";

    return 0;
}
