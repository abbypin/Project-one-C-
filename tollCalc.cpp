#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

double CalcToll(int currentHour, bool morning, bool weekend) {
    double toll = 0.00;
    if (((weekend == 0) && (morning == 1)) && (currentHour < 7 || currentHour == 12)) {
        toll = 1.15;
    } else if (((weekend == 0) && (morning == 1)) && (currentHour >= 7 && currentHour < 10)) {
        toll = 2.95;
    } else if (((weekend == 0) && (morning == 1)) && (currentHour >= 10 && currentHour < 12)) {
        toll = 1.90;
    } else if (((weekend == 0) && (morning == 0)) && (currentHour <= 12 && currentHour < 3)) {
        toll = 1.90;
    } else if (((weekend == 0) && (morning == 0)) && (currentHour >= 3 && currentHour < 8)) {
        toll = 3.95;
    } else if (((weekend == 0) && (morning == 0)) && (currentHour >= 8)) {
        toll = 1.40;
    } else {
        toll = 0.00;
    }//end else-if

    if (((weekend == 1) && (morning == 1)) && (currentHour < 7 || currentHour == 12)) {
        toll = 1.05;
    } else if (((weekend == 1) && (morning == 1)) && (currentHour >= 7 && currentHour < 12)) {
        toll = 1.05;
    } else if (((weekend == 1) && (morning == 0)) && (currentHour <= 12 && currentHour < 8)) {
        toll = 2.15;
    } else if (((weekend == 1) && (morning == 0)) && (currentHour >= 8)) {
        toll = 1.10;
    } else {
        toll = 0.00;
    }//end else-if

    return toll;
}//end CalcToll()

int main() {
    bool isMorning = 0;
    string morning;
    bool isWeekend = 0;
    string weekend;
    string time;
    string hour;
    int index = 0;
    int currentHour = 0;

    cout << "Is it Morning? (yes or no):" << endl;
    cin >> morning;

    if (morning.compare("yes") == 0 || morning.compare("Yes") == 0) {
        isMorning = 1;
    }
    if (morning.compare("no") == 0 || morning.compare("No") == 0) {
        isMorning = 0;
    }//end else-if

    cout << "Is it the Weekend? (yes or no):" << endl;
    cin >> weekend;

    if (weekend.compare("yes") == 0 || weekend.compare("Yes") == 0) {
        isWeekend = 1;
    }
    if (weekend.compare("no") == 0 || weekend.compare("No") == 0) {
        isWeekend = 0;
    }//end else-if

    cout << "What time is it?" << endl;
    cin >> time;
    index = time.find(":");
    hour = time.substr(0, index);
    currentHour = stoi(hour);

    cout << "Toll Amount: " << fixed << setprecision(2) << CalcToll(currentHour, isMorning, isWeekend) << endl;

    return 0;
}//end main()