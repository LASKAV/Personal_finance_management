
#ifndef PERSONAL_FINANCE_MANAGEMENT_CATEGORY_H
#define PERSONAL_FINANCE_MANAGEMENT_CATEGORY_H
#include <iostream>
using namespace std;
struct Category
{
    double Products = 0;       // продукты
    double Restaurants = 0;    // рестораны
    double Medecine = 0;       // медецина
    double Entertainment = 0;  // развлечения
    double Utilities = 0;      // коммуналка

    void Show_expense() const
    {
        cout
            << "Products = " << Products << endl
            << "Restaurants = " << Restaurants << endl
            << "Medecine = " << Medecine << endl
            << "Entertainment = " << Entertainment << endl
            << "Utilities = " << Utilities << endl;
    }
    void Input_categore()
    {
           cout << "Products = "; cin >> Products;
           cout << "Restaurants = "; cin >> Restaurants;
           cout << "Medecine = "; cin >> Medecine;
           cout << "Entertainment = "; cin >> Entertainment;
           cout << "Utilities = "; cin >> Utilities;
    }
};
#endif //PERSONAL_FINANCE_MANAGEMENT_CATEGORY_H
