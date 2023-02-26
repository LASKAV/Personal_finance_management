#include <iostream>
#include <iomanip>
#include <set>
#include <fstream>
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
     const Category GetCategory() const { return category; }

};
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
        << "ID:" << Num_storage << endl
        << "Money " << Сurrent_Amount << endl
        << "Credit limit " << creditLimit << endl;
    }
};
class FinanceManagement
{
	set <MoneyStorage*> storages;
public:
	void AddStorage(MoneyStorage* ptr)
    {
        storages.insert(ptr);
    }
	void DeleteStorage(int number)
    {
        storages.clear();
    }
	void Output()
    {
        for (auto element : storages)
        {
            element->OutPut();
        }
        cout << endl;
    }
    void TopUpStorage()
    {
        int up_moey = 0;
        cout << "Enter how much you want to top up : "; cin >> up_moey;

    }
	//void AddSpendingToStorage();
	//void DayReport();
	//void WeekReport();
	//void MonthReport();
	void RatingMonth()
	{
		multiset <Spending> rating;
		cout << "\nMonth rating - Top 3 spendings!\n";
		unsigned month;
		cout << "Enter month number for the rating: ";
		cin >> month;
		unsigned year;
		cout << "Enter year for rating: ";
		cin >> year;
		for (auto elemSt : storages)
		{
			for (auto elemSp : elemSt->GetSpendings())
			{
				if (elemSp.GetDate().month == month && elemSp.GetDate().year == year)
				{
					rating.insert(elemSp);
				}
			}
		}
		multiset<Spending>::iterator it;
		it = rating.begin();
		unsigned size = 3;
		if (rating.size() < 3) size = rating.size();
		for (int i = 0; i < size; i++)
		{
			(*it).Output_Spending();
			it++;
		}

		cout << "Do you want to save the rating in the file? (yes - 1, no - 0)\n";
		bool yes;
		cin >> yes;
		if (!yes)
			return;
		ofstream out;                           // поток для записи
		out.open("Month rating.txt");       // окрываем файл для записи
		it = rating.begin();
		if (out.is_open())
		{
			out << "Top 3 spendings for the month " << month << " of the year: " << year << "!\n";
			for (int i = 0; i < size; i++)
			{
				out << "Amount of money spending: " << it->Get_money()
                << "  Category of spending: "
                << it->GetCategory().Products << endl
                << it->GetCategory().Restaurants << endl
                << it->GetCategory().Utilities << endl
                << it->GetCategory().Entertainment << endl
                << it->GetCategory().Medecine << endl;
				out << "Date of transaction: " << setw(2) << setfill('0')
                << it->GetDate().day << '/' << setw(2) << setfill('0')
                << it->GetDate().month << '/' << setw(2) << setfill('0')
                << it->GetDate().year << "\n";
				out << "Time of transaction: " << setw(2) << setfill('0')
                << it->GetTime().hours << ':' << setw(2) << setfill('0')
                << it->GetTime().minutes << ':' << setw(2) << setfill('0')
                << it->GetTime().seconds << "\n";
				it++;
			}
		}
	}
	// void RatingWeek();
	// void RatingMonthCategory();
	// void RatingWeekCategory();
};

int main()
{
    int choice_сreation = 0;
    int num_card = 0;
    int num_wall = 0;
    short choice_ = 0;
    short num_spend_card = 0;
    short num_spend_wall = 0;
    MoneyStorage* OBJ_Card[11];  // указатель на базовый абстрактный класс "Хранилище денег"
	MoneyStorage* OBJ_Wall[11];
    Spending* spendings_Card[11];
    Spending* spendings_Wall[11];
	FinanceManagement system;    // создаём систему управления финансами
 do
{
    short choice;
    cout << "\nWelcome to the personal finance management system!\n";
    cout << "1. Card Menu\n";                   // Menu карты
    cout << "2. Wall Menu\n";                   // Menu кошелька
    cout << "3. Enter expense\n";               // Ввести расход
    cout << "4. Exit\n";                        // Выход
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice) {
    case 1:   // Menu карты
  while (true)
  {
        cout << "Menu\n";
        cout << "1. Card\n";
        cout << "2. Replenish card\n";  // Пополнить карту
        cout << "3. Show all cards\n";  // Показать все карты
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice_сreation;
        if (choice_сreation == 4) break;
        switch (choice_сreation)
        {
            case 1:
                num_card += 1;
                OBJ_Card[num_card] = new Card;
                OBJ_Card[num_card]->Input();
                system.AddStorage(OBJ_Card[num_card]);
                break;
            case 2:
                if (choice_ != 0) choice_ = 0;
                cout << "Enter card number : "; cin >> choice_;
                OBJ_Card[choice_]->TopUp();
                break;
            case 3:
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
    case 2:  // Menu кошелька
   while (true)
  {
        cout << "Menu\n";
        cout << "1. Wall\n";
        cout << "2. Replenish wallet\n";  // Пополнить кошелек
        cout << "3. Show all wall\n";     // Показать карты
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice_сreation;
        if (choice_сreation == 4)
        {
            break;
        }
        switch (choice_сreation)
        {
            case 1:
                num_wall += 1;
                OBJ_Wall[num_wall] = new Wallet;
                OBJ_Wall[num_wall]->Input();
                system.AddStorage(OBJ_Wall[num_card]);
            break;
            case 2:
               if (choice_ != 0) choice_ = 0;
                cout << "Enter card number : "; cin >> choice_;
                OBJ_Wall[choice_]->TopUp();
                break;
            case 3:
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
     case 3:  // Ввести расход
         do {
             short choice_soend;
             double meny_spend = 0;
             cout << "\n__Spending__" << endl;
             cout
             << "1. Card" << endl
             << "2. Wall" << endl
             << "3. Show all spending" << endl
             << "4. Exit" << endl;
             cout << "Enter your choice: ";
             cin >> choice_soend;
             if (choice_soend == 4) break;
             switch (choice_soend) {
                 case 1:
                      for (int i = 1; i < num_card + 1; i++)
                        {
                            cout << "Card #" << i << ' '; OBJ_Card[i]->OutPut(); cout << endl;
                        }
                       if (choice_ != 0) choice_ = 0;
                       cout << "Enter card number : "; cin >> choice_;
                       num_spend_card += choice_;
                       OBJ_Card[choice_]->OutPut();
                       spendings_Card[choice_] = new Spending;
                       spendings_Card[choice_]->input_Spen();
                       meny_spend += spendings_Card[choice_]->Get_money();
                       OBJ_Card[choice_]->Spend_money(meny_spend);
                       spendings_Card[choice_]->Output_Spending();
                     break;
                 case 2:
                         for (int i = 1; i < num_spend_card + 1; i++)
                        {
                            cout << "Wall #" << i << ' '; OBJ_Wall[i]->OutPut(); cout << endl;
                        }
                          if (choice_ != 0) choice_ = 0;
                       cout << "Enter card number : "; cin >> choice_;
                       num_spend_wall += choice_;
                       OBJ_Wall[choice_]->OutPut();
                       spendings_Wall[choice_] = new Spending;
                       spendings_Wall[choice_]->input_Spen();
                       meny_spend += spendings_Wall[choice_]->Get_money();
                       OBJ_Wall[choice_]->Spend_money(meny_spend);
                       spendings_Wall[choice_]->Output_Spending();
                     break;
                 case 3:
                     for (int i = 1; i < num_spend_card; ++i)
                     {
                        cout << "Card #" << i << " spend"; spendings_Card[i]->Output_Spending();
                     }
                     for (int i = 1; i < num_spend_wall; ++i)
                     {
                        cout << "Wall #" << i << " spend"; spendings_Wall[i]->Output_Spending();
                     }
                     break;
                 default:
                     cout << "Invalid choice!\n";
             }
         } while (true);
            break;
        case 4:
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