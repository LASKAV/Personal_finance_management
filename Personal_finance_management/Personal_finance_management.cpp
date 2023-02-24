#include <iostream>
#include <iomanip>
#include <set>
#include "Struct_financ.h"
using namespace std;

/*
02.02
Продумать, какие сущности будут использоваться в программе.
Создать базовый класс для "Хранилища денег". Назвать этот класс MoneyStorage.
Наполнить этот класс полями и прототипами методов. Прислать в качестве выполненного ДЗ определение этого класса.
09.02
Создать класс для затрат. Назвать этот класс Spending.
Наполнить этот класс полями и прототипами методов. Прислать в качестве выполненного ДЗ определение этого класса
(пока можно ограничиться прототипами методов - тела методов можно пока не писать).
10.02
Создать классы для банковской карты (Card) и кошелька (Wallet). Они будут наследниками класса MoneyStorage.
Наполнить эти классы полями и прототипами методов. Прислать в качестве выполненного ДЗ определения этих классов
(пока можно ограничиться прототипами методов - тела методов можно пока не писать).
*/

class Spending      // Расходы
{
private:
    float money;
    Category category;
    Date data;
    Time time;
public:
     Spending();
     void Output_Spending() const
     {
         cout << setw(5) << "__SPENDING__" << endl
         << "Money: " << money << endl
         << setw(5) << "_Category" << endl ;
         category.Show_expense();
         cout << setw(5) << "_Data" << endl;
         data.Output();
         cout << setw(5) << "_Time" << endl;
         time.Output();
     }
};

class MoneyStorage                  // Basic "Хранилища денег"
{
protected:
    double Сurrent_Amount;          // Текущее количество денег
    long Num_storage;               // Номер Хранилища
    float creditLimit;              // Кредитный лимит
    multiset<Spending> spendings;
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

    void TopUp(double sum_add)  // Пополнение
    {
        cout << "__Replenishment__" << endl
        << "Enter sum :"; cin >> sum_add;
        this->Сurrent_Amount += sum_add;
    }
    ~MoneyStorage()
    {
        cout << "Destructor MoneyStorage" << endl;
    }
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

        cout << "Enter Bank name "; cin >> name_bank;
        cout << "Enter ID:"; cin >> num_stor;
        cout << "Enter money "; cin >> current_amout;
        cout << "Enter credit limit "; cin >> credit_limit;

        this->bankName = name_bank;
        this->Num_storage = num_stor;
        this->Сurrent_Amount = current_amout;
        this->creditLimit = credit_limit;

    }
    void Output()
    {
        cout
                << "__" << bankName << "__" << endl
                << "ID:" << Num_storage << endl
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
        creditLimit = 0;
    }
    Wallet(int id,long num_stor, double current_amout,float credit_limit)
    {
        this->Num_storage = num_stor;
        this->Сurrent_Amount = current_amout;
        this->creditLimit = credit_limit;
    }
    void Input()
    {

        long num_stor;
        double current_amout;
        float credit_limit;

       cout << "Enter ID: "; cin >> num_stor ;
       cout << "Enter money "; cin >> current_amout ;
       cout << "Enter credit limit "; cin >> credit_limit ;

        this->Num_storage = num_stor;
        this->Сurrent_Amount = current_amout;
        this->creditLimit = credit_limit;
    }
     void Output()
    {
        cout
                << "__" << "Wallet" << "__" << endl
                << "ID:" << Num_storage << endl
                << "Money " << Сurrent_Amount << endl
                << "Credit limit " << creditLimit << endl;
    }
};


int main()
{


    while (true)    // Menu
    {
        short choice;
        cout << "Welcome to the personal finance management system!\n";   
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
            break;
        case 2:
            break;
        case 3:
            do{
                short choice_expense;
                double price = 0.0;
                cout
                    << "1. Products\n"
                    << "2. Restaurants\n"
                    << "3. Medecine\n"
                    << "4. Entertainment\n"
                    << "5. Utilities\n"
                    << "6. Exit\n"
                    << "Enter your choice: ";
                cin >> choice_expense;
                if (price != 0.0) price = 0.0;
                if (choice_expense == 6)
                {
                    system("cls");
                    break;
                }
                switch (choice_expense)
                {
                case 1:
                    cout << "Enter Products : "; cin >> price;
                    break;
                case 2:
                    cout << "Enter Restaurants : "; cin >> price;
                    break;
                case 3:
                    cout << "Enter Medecine : "; cin >> price;
                    break;
                case 4:
                    cout << "Enter Entertainment : "; cin >> price;
                    break;
                case 5:
                    cout << "Enter Utilities : "; cin >> price;
                    break;
                case 6:
                    break;
                default:
                    cout << "Invalid choice!\n";
                }
            } while (true);
            break;
        case 4:
            system("cls");
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