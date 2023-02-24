#include <iostream>
#include <iomanip>
#include <set>
#include "Struct_financ.h"
using namespace std;

class Spending{
private:
    double money;
    Category category;
    Date data;
    Time time;
public:
    Spending() = default;
  virtual void input_Spen()
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
         cout << setw(5) << "__SPENDING__" << endl
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
};
class MoneyStorage
        {                  // Basic "Хранилища денег"
protected:
    double Сurrent_Amount;           // Текущее количество денег
    long Num_storage;                // Номер Хранилища
    float creditLimit;               // Кредитный лимит
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
    double Get_Сurrent_Amount()
    {
        return this->Сurrent_Amount;
    }
    short Get_Num_storage()
    {
        return this->Num_storage;
    }
    void TopUp()  // Пополнение
    {
        double sum_add;
        cout << "__Replenishment__" << endl
        << "Enter sum :"; cin >> sum_add;
        this->Сurrent_Amount += sum_add;
    }
    ~MoneyStorage()
    {
        cout << "Destructor MoneyStorage" << endl;
    }
    virtual void OutPut() = 0;
};
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
        << "ID " << Num_storage << endl
        << "Money " << Сurrent_Amount << endl
        << "Credit limit " << creditLimit << endl;
    }
};
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
        << "ID:" << Num_storage << endl
        << "Money " << Сurrent_Amount << endl
        << "Credit limit " << creditLimit << endl;
    }
};

int main()
{
    MoneyStorage* OBJ_Card;
    MoneyStorage* OBJ_Wall;

    Spending OBJ_Spend;

    Card test_C;
    test_C.Input();

    Wallet test_W;
    test_W.Input();

    OBJ_Card = new Card{test_C};
    OBJ_Wall = new Wallet{test_W};

while (true)    // Menu
{
    short choice;
    cout << "\nWelcome to the personal finance management system!\n";
    cout << "1. Replenish wallet\n";            // Пополнить кошелек
    cout << "2. Replenish card\n";              // Пополнить карту
    cout << "3. Enter expense\n";               // Ввести расход
    cout << "4. Generate report\n";             // Сформировать отчет
    cout << "5. Generate rating\n";             // Сгенерировать рейтинг
    cout << "6. Save reports and ratings\n";    // Сохранить отчеты и рейтинги
    cout << "7. Exit\n";                        // Выход
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice) {
    case 1:
        OBJ_Wall->TopUp();
        OBJ_Wall->OutPut();
        break;
    case 2:
        OBJ_Card->TopUp();
        OBJ_Card->OutPut();
        break;
    case 3:
        OBJ_Spend.input_Spen();
        break;
    case 4:
        OBJ_Spend.Output_Spending();
        break;
    case 5:
        break;
    case 6:
        break;
    case 7:
        return 0;
    default:
        cout << "Invalid choice!\n";
    }
}

    return 0;
}

/*
Создайте систему управления персональными финансами.
Система должна иметь следующие возможности:
■■ Наличие разных кошельков и карт (дебетовых/кредитных);
■■ Пополнение кошельков и карт;
■■ Внесение затрат. Каждая затрата относится к определенной категории;
■■ Формирование отчетов по затратам и категориям:
• день;
• неделя;
• месяц.
■■ Формирование рейтингов по максимальным суммам:
• ТОП-3 затрат:
неделя;
месяц.
• ТОП-3 категорий:
неделя;
месяц.
■■ Сохранение отчетов и рейтингов в файл.
*/