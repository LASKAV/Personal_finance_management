
#ifndef PERSONAL_FINANCE_MANAGEMENT_CARD_H
#define PERSONAL_FINANCE_MANAGEMENT_CARD_H
#include <iostream>
#include "MoneyStorage.h"

using namespace std;

class Card : public MoneyStorage
{
    string bankName;
public:
    Card() : MoneyStorage()
    {
        bankName = "";
        Num_storage = 0;
        Сurrent_Amount = 0;
        creditLimit = 0;
    }
    Card(string name_bank ,long num_stor, double current_amout,float credit_limit)
    {
        this->bankName = name_bank;
        this->Num_storage = num_stor;
        this->Сurrent_Amount = current_amout;
        this->creditLimit = credit_limit;
    }
    Card(multiset<Spending>& temp_spendings, string name_bank ,long num_stor, double current_amout,float credit_limit)
    {
        this->spendings = temp_spendings;
        this->bankName = name_bank;
        this->Num_storage = num_stor;
        this->Сurrent_Amount = current_amout;
        this->creditLimit = credit_limit;
    }
    void Input()
    {

        string name_bank;
        long num_stor;
        double current_amout;
        float credit_limit;

        cout << "__Card__" << endl;
        cout << "Enter Bank name: "; cin >> name_bank;
        cout << "Enter ID: "; cin >> num_stor;
        cout << "Enter money: "; cin >> current_amout;
        cout << "Enter credit limit: "; cin >> credit_limit;

        this->bankName = name_bank;
        this->Num_storage = num_stor;
        this->Сurrent_Amount = current_amout;
        this->creditLimit = credit_limit;

    }
    void OutPut()
    {
        cout << endl << "__" << bankName << "__" << endl
        << "ID: " << Num_storage << endl
        << "Money: " << Сurrent_Amount << "$" << endl
        << "Credit limit: " << creditLimit << endl;

    }
};


#endif //PERSONAL_FINANCE_MANAGEMENT_CARD_H
