#include <iostream>

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


class MoneyStorage                  // Basic "Хранилища денег"
{   
protected:
    double Сurrent_Amount;          // Текущее количество денег 
public:
    MoneyStorage()                  // Конструктор без параметров                
    {
        Сurrent_Amount = 00.00;
    }                                       
     MoneyStorage(double Сurrent_Amount)     // Конструктор с одним параметром 
    {
        this->Сurrent_Amount = Сurrent_Amount;
    }
     virtual void Add_Money(double Money) = 0;
     virtual void Subtract_Money(double Money) = 0;

    // virtual void Add_Money(double Money)
    // {
    //     this->Сurrent_Amount += Money;
    // }
    // virtual void Subtract_Money(double Money)
    // {
    //     this->Сurrent_Amount -= Money;
    // }
    // double Show_MoneyStorage()
    // {
    //     cout << " Сurrent_Amount = " << this->Сurrent_Amount << endl;
    // 
    //     return this->Сurrent_Amount;
    // }
    ~MoneyStorage()
    {
        cout << "Destructor MoneyStorage" << endl;
    }
};

class Spending      // Расходы
{
private:
    int Products;       // продукты
    int Restaurants;    // рестораны
    int Medecine;       // медецина
    int Entertainment;  // развлечения
    int Utilities;      // коммуналка  
public:
    Spending()
    {
        Products = NULL;
        Restaurants = NULL;
        Medecine = NULL;
        Entertainment = NULL;
        Utilities = NULL;
    }

    void Show_expense()
    {
        cout
            << "Products = " << Products << endl
            << "Restaurants = " << Restaurants << endl
            << "Medecine = " << Medecine << endl
            << "Entertainment = " << Entertainment << endl
            << "Utilities = " << Utilities << endl;
    }

};

class Card : public MoneyStorage
{

};

class Wallet : public MoneyStorage
{

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
            break;
        case 4:
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