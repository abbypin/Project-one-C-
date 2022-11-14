#include <iostream>
#include <string>
using namespace std;

double CalcToll(int currentHour, bool morning, bool weekend) {
    double toll = 0.00;
    if (!(weekend) && (morning) && (currentHour < 7 || currentHour == 12)) {
        toll = 1.15;
    } else if (!(weekend) && (morning) && (currentHour >= 7 && currentHour < 10)) {
        toll = 2.95;
    } else if (!(weekend) && (morning) && (currentHour >= 10 && currentHour < 12)) {
        toll = 1.90;
    } else if ((!weekend && !morning) && (currentHour >= 12 && currentHour < 3)) {
        toll = 1.90;
    } else if ((!weekend && !morning) && (currentHour >= 3 && currentHour < 8)) {
        toll = 3.95;
    } else if ((!weekend && !morning) && (currentHour >= 8)) {
        toll = 1.40;
    } else {
        toll = 0.00;
    }//end else-if

    if ((weekend && morning) && (currentHour < 7 || currentHour == 12)) {
        toll = 1.05;
    } else if ((weekend && morning) && (currentHour >= 7 && currentHour < 12)) {
        toll = 1.05;
    } else if ((weekend && !morning) && (currentHour >= 12 && currentHour < 8)) {
        toll = 2.15;
    } else if ((weekend && !morning) && (currentHour >= 8)) {
        toll = 1.10;
    } else {
        toll = 0.00;
    }//end else-if

    return toll;
}//end CalcToll()

int main() {
    bool isMorning;
    string morning;
    bool isWeekend;
    string weekend;
    string time;
    string hour;
    int index = 0;
    int currentHour = 0;

    cout << "Is it Morning? (yes or no):" << endl;
    cin >> morning;

    if (morning.compare("yes") || morning.compare("Yes")) {
        isMorning = true;
    } else if (morning.compare("no") || morning.compare("No")) {
        isMorning = false;
    } else {
        isMorning = false;
    }//end else-if

    cout << "Is it the Weekend? (yes or no):" << endl;
    cin >> weekend;

    if (weekend.compare("yes") || weekend.compare("Yes")) {
        isWeekend = true;
    } else if (weekend.compare("no") || weekend.compare("No")) {
        isWeekend = false;
    } else {
        isWeekend = false;
    }//end else-if

    cout << "What time is it?" << endl;
    cin >> time;
    index = time.find(":");
    hour = time.substr(0, index);
    currentHour = stoi(hour);

    cout << "Toll Amount: " << CalcToll(currentHour, isMorning, isWeekend) << endl;

    return 0;
}//end main()