
#ifndef PERSONAL_FINANCE_MANAGEMENT_DATE_H
#define PERSONAL_FINANCE_MANAGEMENT_DATE_H
#include <iostream>
#include <iomanip>
using namespace std;

struct Date
{
    unsigned day;
    unsigned month;
    unsigned year;
    void Output()const
    {
        cout
        << setw(2) << setfill('0') << day << "/"
        << setw(2) << setfill('0') << setfill('0') << month << "/"
        << setw(2) << setfill('0') << year;
    }
    void Input()
    {
        cout << "Enter day of spending: "; cin >> day;
        cout << "Enter month of spending: "; cin >> month;
        cout << "Enter year of spending: "; cin >> year;
    }
};

#endif //PERSONAL_FINANCE_MANAGEMENT_DATE_H
