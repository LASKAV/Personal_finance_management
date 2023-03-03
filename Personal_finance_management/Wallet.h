
#ifndef PERSONAL_FINANCE_MANAGEMENT_WALLET_H
#define PERSONAL_FINANCE_MANAGEMENT_WALLET_H
#include <iostream>
#include "MoneyStorage.h"

using namespace std;

class Wallet : public MoneyStorage
{
public:
    Wallet() : MoneyStorage()
    {
        Num_storage = 0;
        Сurrent_Amount = 0;
    }
    Wallet(long num_stor, double current_amout)
    {
        this->Num_storage = num_stor;
        this->Сurrent_Amount = current_amout;
    }
    Wallet(multiset<Spending>& temp_spendings,long num_stor, double current_amout)
    {
        this->spendings = temp_spendings;
        this->Num_storage = num_stor;
        this->Сurrent_Amount = current_amout;
    }
    void Input()
    {
        long num_stor;
        double current_amout;
        float credit_limit;

        cout << "__Wallet__" << endl;
        cout << "Enter ID: "; cin >> num_stor ;
        cout << "Enter money: "; cin >> current_amout ;

        this->Num_storage = num_stor;
        this->Сurrent_Amount = current_amout;
    }
     void OutPut()
    {
        cout << endl << "__" << "Wallet" << "__" << endl
        << "ID: " << Num_storage << endl
        << "Money: " << Сurrent_Amount << "$" << endl
        << "Credit limit: " << creditLimit << endl;
    }
};
#endif //PERSONAL_FINANCE_MANAGEMENT_WALLET_H
