
#ifndef PERSONAL_FINANCE_MANAGEMENT_SPENDING_H
#define PERSONAL_FINANCE_MANAGEMENT_SPENDING_H
#include <iostream>
#include <iomanip>
#include "Category.h"
#include "Date.h"
#include "Time.h"

using namespace std;

class Spending{
private:
    double money;
    Category category;
    Date data;
    Time time;
public:
    Spending() = default;
    Spending(float mon, Category cat, Date d, Time t)
    {
        this->money = mon;
        this->category = cat;
        this->data = d;
        this->time = t;
    }
    void input_Spen()
    {
         cout << "Enter category : " << endl;
         do {
                short choice_expense;
                Category price;
                cout
                    << "1. Products\n"
                    << "2. Restaurants\n"
                    << "3. Medecine\n"
                    << "4. Entertainment\n"
                    << "5. Utilities\n"
                    << "6. Exit\n"
                    << "Enter your choice: ";
                cin >> choice_expense;
                if (choice_expense == 6)
                {
                    break;
                }
                switch (choice_expense) {
                    case 1:
                        cout << "Enter Products : ";
                        cin >> price.Products;
                        category.Products += price.Products;
                        break;
                    case 2:
                        cout << "Enter Restaurants : ";
                        cin >> price.Restaurants;
                        category.Restaurants += price.Restaurants;
                        break;
                    case 3:
                        cout << "Enter Medecine : ";
                        cin >> price.Medecine;
                        category.Medecine += price.Medecine;
                        break;
                    case 4:
                        cout << "Enter Entertainment : ";
                        cin >> price.Entertainment;
                        category.Entertainment += price.Entertainment;
                        break;
                    case 5:
                        cout << "Enter Utilities : ";
                        cin >> price.Utilities;
                        category.Utilities += price.Utilities;
                        break;
                    case 6:
                        break;
                    default:
                        cout << "Invalid choice!\n";
                }
            } while (true);
        this->money += category.Products;
        this->money += category.Restaurants;
        this->money += category.Medecine;
        this->money += category.Entertainment;
        this->money += category.Utilities;
        data.Input();
        time.Input();
    }
     void Output_Spending() const
     {
         cout << "\n" << setw(5) << "__SPENDING__" << endl
         << "Money: " << money << "$" << endl
         << setw(5) << "_Category" << endl ;
         category.Show_expense();
         cout << setw(5) << "_Data" << endl;
         data.Output();
         cout << setw(5) << "_Time" << endl;
         time.Output();
     }
     bool operator<(const Spending temp) const
	 {
		return money > temp.money;
	 }
     double Get_money() const { return this->money; }
     const Date GetDate() const { return data; }
	 const Time GetTime() const { return time; }
     const Category GetCategory() const { return category; }

};
#endif //PERSONAL_FINANCE_MANAGEMENT_SPENDING_H
