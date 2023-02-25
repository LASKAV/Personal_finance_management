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
        << "Enter sum :"; cin >> sum_add;
        this->Сurrent_Amount += sum_add;
    }
    ~MoneyStorage()
    {
        cout << "Destructor MoneyStorage" << endl;
    }
    virtual void OutPut() = 0;
    virtual void Input() = 0;
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

    int choice_сreation = 0;
    MoneyStorage* OBJ_Card[11];
    MoneyStorage* OBJ_Wall[11];

    short num_card = 0;
    short num_wall = 0;

do
{
    short choice;
    cout << "\nWelcome to the personal finance management system!\n";
    cout << "1. Card creation\n";               // Создание карты
    cout << "2. Wall creation\n";               // Создание кошелька
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
  while (true)
  {
        cout << "Menu\n";
        cout << "1. Card\n";
        cout << "2. Show all cards\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice_сreation;
        if (choice_сreation == 3)
        {
            break;
        }
        switch (choice_сreation)
        {
            case 1:
                num_card += 1;
                cout << "num =" << num_card << endl;
                OBJ_Card[num_card] = new Card;
                OBJ_Card[num_card]->Input();
            break;
            case 2:
                cout << "num =" << num_card << endl;
                for (int i = 1; i < num_card + 1; i++)
                {
                    cout << "Card #" << i << ' '; OBJ_Card[i]->OutPut(); cout << endl;
                }

                break;
        default: cout << "Invalid choice\n";
            break;
        }
    }
  break;
    case 2:
   while (true)
  {
        cout << "Menu\n";
        cout << "1. Wall\n";
        cout << "2. Show all wall\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice_сreation;
        if (choice_сreation == 3)
        {
            break;
        }
        switch (choice_сreation)
        {
            case 1:
                num_wall += 1;
                cout << "num =" << num_wall << endl;
                OBJ_Wall[num_wall] = new Wallet;
                OBJ_Wall[num_wall]->Input();
            break;
            case 2:
                cout << "num =" << num_wall << endl;
                for (int i = 1; i < num_wall + 1; i++)
                {
                    cout << "Wall #" << i << ' '; OBJ_Wall[i]->OutPut(); cout << endl;
                }
                break;
        default: cout << "Invalid choice\n";
            break;
        }
    }
    break;

//      case 3:
//          do {
//              short choice_soend;
//              double meny_spend = 0;
//              cout << "__Spending__" << endl;
//              cout
//              << "1. Card" << endl
//              << "2. Wall" << endl
//              << "3. Exit" << endl;
//              cout << "Enter your choice: ";
//              cin >> choice_soend;
//              if (choice_soend == 3)
//              {
//                  break;
//              }
//              switch (choice_soend) {
//                  case 1:
//                      OBJ_Spend.input_Spen();
//                      if (meny_spend != 0)
//                      {
//                          meny_spend = 0;
//                      }
//                      meny_spend = OBJ_Spend.Get_money();
//                      OBJ_Card->Spend_money(meny_spend);
//                      OBJ_Card->OutPut();
//                      break;
//                  case 2:
//                      OBJ_Spend.input_Spen();
//                      if (meny_spend != 0)
//                      {
//                          meny_spend = 0;
//                      }
//                      meny_spend = OBJ_Spend.Get_money();
//                      OBJ_Wall->Spend_money(meny_spend);
//                      OBJ_Wall->OutPut();
//                      break;
//                  case 3:
//                      cout << "Exit spending" << endl;
//                      break;
//                  default:
//                      cout << "Invalid choice!\n";
//              }
//          } while (true);
//      break;
//  case 4:
//      OBJ_Wall->OutPut();
//      OBJ_Card->OutPut();
//      OBJ_Spend.Output_Spending();
//      break;
//  case 5:
//      break;
//  case 6:
//      break;
  case 7:
        return 0;
    default:
        cout << "Invalid choice!\n";
    }
} while (true);

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