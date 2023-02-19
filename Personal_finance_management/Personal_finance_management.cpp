#include <iostream>
#include <iomanip>

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
        cout << "Enter day of spending:"; cin >> day;
        cout << "Enter month of spending:"; cin >> month;
        cout << "Enter year of spending:"; cin >> year;
    }
};

bool isLeap(int year)  // определение является ли высокостный год
{
if (year % 400 == 0)
{
    return true;
}
if (year % 4 == 0 && year != 0)
{
    return true;
}
    return false;
}

class MoneyStorage                  // Basic "Хранилища денег"
{   
protected:
    double Сurrent_Amount;          // Текущее количество денег

    short Num_storage;              // Номер Хранилища
public:
    MoneyStorage()                  // Конструктор без параметров                
    {
        Сurrent_Amount = 00.00;
        Num_storage = 0;
    }
    MoneyStorage(double Сurrent_Amount, short Num_storage)     // Конструктор с одним параметром
    {
        this->Сurrent_Amount = Сurrent_Amount;
        this->Num_storage = Num_storage;
    }
    double Get_Сurrent_Amount()
    {
        return this->Сurrent_Amount;
    }
    short Get_Num_storage()
    {
        return this->Num_storage;
    }
    double Show_MoneyStorage()
    {
        cout << " Сurrent_Amount = " << this->Сurrent_Amount << endl;
    
        return this->Сurrent_Amount;
    }
    ~MoneyStorage()
    {
        cout << "Destructor MoneyStorage" << endl;
    }
    virtual void Add_Money(double Money) = 0;
    virtual void Subtract_Money(double Money) = 0;
};

/*
09.02
Создать класс для затрат. Назвать этот класс Spending.
Наполнить этот класс полями и прототипами методов. Прислать в качестве выполненного ДЗ определение этого класса
(пока можно ограничиться прототипами методов - тела методов можно пока не писать).
*/

struct Category
{
    double Products;       // продукты
    double Restaurants;    // рестораны
    double Medecine;       // медецина
    double Entertainment;  // развлечения
    double Utilities;      // коммуналка

    void Show_expense()
    {
        cout
            << "Products = " << Products << endl
            << "Restaurants = " << Restaurants << endl
            << "Medecine = " << Medecine << endl
            << "Entertainment = " << Entertainment << endl
            << "Utilities = " << Utilities << endl << endl;
    }
};

class Spending      // Расходы
{
private:
    float money;
    Category category;

public:

};

class Card : public MoneyStorage
{

};

class Wallet : public MoneyStorage
{

};


int main()
{
    Spending Spend;
    Date date;
    date.Input();
    date.Output();

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