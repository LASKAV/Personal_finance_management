
#ifndef PERSONAL_FINANCE_MANAGEMENT_TIME_H
#define PERSONAL_FINANCE_MANAGEMENT_TIME_H
#include <iostream>
#include <iomanip>
using namespace std;

struct  Time
{
    unsigned hours;
    unsigned minutes;
    unsigned seconds;
    void Output() const
    {
         cout
        << setw(2) << setfill('0') << hours << ":"
        << setw(2) << setfill('0') << setfill('0') << minutes << ":"
        << setw(2) << setfill('0') << seconds;
    }
    void Input()
    {
        cout << "Enter hours of spending: "; cin >> hours;
        cout << "Enter minutes of spending: "; cin >> minutes;
        cout << "Enter seconds of spending: "; cin >> seconds;
    }
};
#endif //PERSONAL_FINANCE_MANAGEMENT_TIME_H
