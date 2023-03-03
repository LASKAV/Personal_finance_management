
#ifndef PERSONAL_FINANCE_MANAGEMENT_MONEYSTORAGE_H
#define PERSONAL_FINANCE_MANAGEMENT_MONEYSTORAGE_H
#include <iostream>
#include <set>
#include "Spending.h"
using namespace std;
class MoneyStorage
        {                  // Basic "Хранилища денег"
protected:
    double Сurrent_Amount;           // Текущее количество денег
    long Num_storage;                // Номер Хранилища
    float creditLimit;               // Кредитный лимит
    multiset<Spending>spendings;    // {  double money;
                                     //    Category category;
                                     //    Date data;
                                     //    Time time; }
public:
    MoneyStorage()                  // Конструктор без параметров
    {
        Сurrent_Amount = 00.00;
        Num_storage = 0;
        creditLimit = 0;
    }
    MoneyStorage(double Сurrent_Amount, long Num_storage, float Credit_limit)
    {
        this->Сurrent_Amount = Сurrent_Amount;
        this->Num_storage = Num_storage;
        this->creditLimit = Credit_limit;
    }
    MoneyStorage(multiset<Spending>& temp_spendings, double Сurrent_Amount, long Num_storage, float  Credit_limit)
    {
        this->spendings = temp_spendings;
        this->Сurrent_Amount = Сurrent_Amount;
        this->Num_storage = Num_storage;
        this->creditLimit = Credit_limit;
    }
    double Get_Сurrent_Amount()
    {
        return this->Сurrent_Amount;
    }
    long Get_Num_storage()
    {
        return this->Num_storage;
    }
    void Spend_money(double temp_money)
    {
        this->Сurrent_Amount -= temp_money;
    }
    void TopUp()  // Пополнение
    {
        double sum_add;
        cout << "__Replenishment__" << endl
        << "Enter sum: "; cin >> sum_add;
        this->Сurrent_Amount += sum_add;
    }
    multiset<Spending> GetSpendings() const { return spendings; }

    ~MoneyStorage()
    {
        cout << "Destructor MoneyStorage" << endl;
    }
    virtual void OutPut() = 0;
    virtual void Input() = 0;
};
#endif //PERSONAL_FINANCE_MANAGEMENT_MONEYSTORAGE_H
