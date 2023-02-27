#include <iostream>
#include <iomanip>
#include <set>
#include <fstream>
#include <ctime>

using namespace std;

struct Category
{
    double Products = 0;       // продукты
    double Restaurants = 0;    // рестораны
    double Medecine = 0;       // медецина
    double Entertainment = 0;  // развлечения
    double Utilities = 0;      // коммуналка

    void Show_expense() const
    {
        cout
            << "Products = " << Products << endl
            << "Restaurants = " << Restaurants << endl
            << "Medecine = " << Medecine << endl
            << "Entertainment = " << Entertainment << endl
            << "Utilities = " << Utilities << endl;
    }
    void Input_categore()
    {
           cout << "Products = "; cin >> Products;
           cout << "Restaurants = "; cin >> Restaurants;
           cout << "Medecine = "; cin >> Medecine;
           cout << "Entertainment = "; cin >> Entertainment;
           cout << "Utilities = "; cin >> Utilities;
    }
};
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
        cout << "Enter day of spending: "; cin >> day;
        cout << "Enter month of spending: "; cin >> month;
        cout << "Enter year of spending: "; cin >> year;
    }
};
struct  Time
{
    unsigned hours;
    unsigned minutes;
    unsigned seconds;
    void Output() const
    {
         cout
        << setw(2) << setfill('0') << hours << ":"
        << setw(2) << setfill('0') << setfill('0') << minutes << ":"
        << setw(2) << setfill('0') << seconds;
    }
    void Input()
    {
        cout << "Enter hours of spending: "; cin >> hours;
        cout << "Enter minutes of spending: "; cin >> minutes;
        cout << "Enter seconds of spending: "; cin >> seconds;
    }
};
bool isLeap(int year);
int diff_between_dates(Date begin_date, Date end_date);
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
        << "ID: " << Num_storage << endl
        << "Money: " << Сurrent_Amount << "$" << endl
        << "Credit limit: " << creditLimit << endl;

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
        << "ID: " << Num_storage << endl
        << "Money: " << Сurrent_Amount << "$" << endl
        << "Credit limit: " << creditLimit << endl;
    }
};

void line();
void Show_day_report(multiset <Spending> report_spend_Wall,multiset <Spending> report_spend_Card, int size);
void Monthly_report(multiset <Spending> report_spend_Wall,multiset <Spending> report_spend_Card);
void Show_week_report(multiset <Spending> report_spend_Wall,multiset <Spending> report_spend_Card, int size);
void Show_month_report(multiset <Spending> report_spend_Wall,multiset <Spending> report_spend_Card, int size);
void Show_week_rating(multiset <Spending> report_spend_Wall,multiset <Spending> report_spend_Card);
int main()
{
     Spending* spendings_Card[11];
     Spending* spendings_Wall[11];
     multiset<Spending> report_spend_Wall;
     multiset<Spending> report_spend_Card;
     int choice_сreation = 0;
     int num_card = 0;
     int num_wall = 0;
     short choice_ = 0;
     short num_spend_card = 0;
     short num_spend_wall = 0;
     int size = 0;
     MoneyStorage* OBJ_Card[11];
	 MoneyStorage* OBJ_Wall[11];

    do {
    short choice;
    cout
     << "\nWelcome!\n"
     << "1. Card Menu\n"                          // Menu карты
     << "2. Wall Menu\n"                          // Menu кошелька
     << "3. Enter expense\n"                      // Ввести расход
     << "4. Show day report\n"                    // Затраты за день
     << "5. Show week report\n"                   // Затраты за неделю
     << "6. Show month report\n"                  // Затраты за месяц
     << "7. Show week rating\n"                   // ТОП-3 затрат за неделю
     << "8. Show month rating\n"                  // ТОП-3 затрат за месяц
     << "9. Show week rating for categories\n"    // ТОП-3 категорий за неделю
     << "10. Show month rating for categories\n"  // ТОП-3 категорий за месяц
     << "11. Exit\n";                             // Выход
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
                       report_spend_Card.insert(*spendings_Card[choice_]);
                     break;
                 case 2:
                         for (int i = 1; i < num_wall + 1; i++)
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
                       report_spend_Wall.insert(*spendings_Wall[choice_]);
                     break;
                 case 3:
                     line();
                     for (int i = 1; i < num_spend_card; ++i)
                     {
                        cout << "Card #" << i << " spend"; spendings_Card[i]->Output_Spending();
                     }
                     line();
                     for (int i = 1; i < num_spend_wall; ++i)
                     {
                        cout << "Wall #" << i << " spend"; spendings_Wall[i]->Output_Spending();
                     }
                     line();
                     break;
                 default:
                     cout << "Invalid choice!\n";
             }
         } while (true);
            break;
     case 4:  // Затраты за день
         size = num_spend_card + num_spend_wall;
         Show_day_report(report_spend_Wall,report_spend_Card,size);
        break;
     case 5:  // Затраты за неделю
        size = num_spend_card + num_spend_wall;
        Show_week_report(report_spend_Wall,report_spend_Card,size);
         break;
     case 6:  // Затраты за месяц
            size = num_spend_card + num_spend_wall;
            Show_month_report(report_spend_Wall,report_spend_Card,size);
         break;
     case 7:  // ТОП-3 затрат за неделю
            Show_week_rating(report_spend_Wall,report_spend_Card);
         break;
     case 8:  // ТОП-3 затрат за месяц
            Monthly_report(report_spend_Wall,report_spend_Card);
         break;
     case 9:  // ТОП-3 категорий за неделю

         break;
     case 10:  // ТОП-3 категорий за месяц

         break;
        default:
            cout << "Invalid choice!\n";
    }
} while (true);

    return 0;
}
void date_now()
{
    time_t t = time(nullptr);
    tm* now = localtime(&t);

    cout
    << "Current Date: " << now->tm_mday << '/'
    << (now->tm_mon + 1) << '/'
    << (now->tm_year + 1900) << endl;
}
void line (){
    cout << endl;
    for (int i = 0; i < 15; ++i) {
        cout << "-";
    }
    cout << endl;
}
bool isLeap(int year){
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
int diff_between_dates(Date begin_date, Date end_date){
	int day_begin = begin_date.day;
	int month_begin = begin_date.month;
	int year_begin = begin_date.year;
	int day_end = end_date.day;
	int month_end = end_date.month;
	int year_end = end_date.year;
	enum months { jan = 31, feb = 28, march = 31, apr = 30, may = 31, jun = 30, jul = 31, aug = 31, sept = 30, oct = 31, nov = 30, dec = 31 };
	int alldays_begin=0, alldays_end=0;
	switch (month_begin) {
	case 1: alldays_begin = day_begin; break;
	case 2: alldays_begin = day_begin + jan; break;
	case 3: alldays_begin = day_begin + feb + jan; break;
	case 4: alldays_begin = day_begin + march + feb + jan; break;
	case 5: alldays_begin = day_begin + apr + march + feb + jan; break;
	case 6: alldays_begin = day_begin + may + apr + march + feb + jan; break;
	case 7: alldays_begin = day_begin + jun + may + apr + march + feb + jan; break;
	case 8: alldays_begin = day_begin + jul + jun + may + apr + march + feb + jan; break;
	case 9: alldays_begin = day_begin + aug + jul + jun + may + apr + march + feb + jan; break;
	case 10: alldays_begin = day_begin + sept + aug + jul + jun + may + apr + march + feb + jan; break;
	case 11: alldays_begin = day_begin + oct + sept + aug + jul + jun + may + apr + march + feb + jan; break;
	case 12: alldays_begin = day_begin + nov + oct + sept + aug + jul + jun + may + apr + march + feb + jan; break;
	}
	switch (month_end) {
	case 1: alldays_end = day_end; break;
	case 2: alldays_end = day_end + jan; break;
	case 3: alldays_end = day_end + feb + jan; break;
	case 4: alldays_end = day_end + march + feb + jan; break;
	case 5: alldays_end = day_end + apr + march + feb + jan; break;
	case 6: alldays_end = day_end + may + apr + march + feb + jan; break;
	case 7: alldays_end = day_end + jun + may + apr + march + feb + jan; break;
	case 8: alldays_end = day_end + jul + jun + may + apr + march + feb + jan; break;
	case 9: alldays_end = day_end + aug + jul + jun + may + apr + march + feb + jan; break;
	case 10: alldays_end = day_end + sept + aug + jul + jun + may + apr + march + feb + jan; break;
	case 11: alldays_end = day_end + oct + sept + aug + jul + jun + may + apr + march + feb + jan; break;
	case 12: alldays_end = day_end + nov + oct + sept + aug + jul + jun + may + apr + march + feb + jan; break;
	}

	// определим количество високосных годов между двумя датами, но без цикла
	// сначала найдем високосных лет между начальным и конечным годом (не включительно)

	int leap_summ = 0;
	int leap_summ_4 = (year_end - 1) / 4 - (year_begin / 4 + 1) + 1;   // количество лет, кратных 4, между данными годами
	int leap_summ_100 = (year_end - 1) / 100 - (year_begin / 100 + 1) + 1;   // количество лет, кратных 100, между данными годами
	int leap_summ_400 = (year_end - 1) / 400 - (year_begin / 400 + 1) + 1;   // количество лет, кратных 400, между данными годами
	leap_summ = leap_summ_4 - leap_summ_100 + leap_summ_400;

	// если начальный год високосный и дата раньше 1 марта, то учитываем, что он високосный
	if (isLeap(year_begin) && month_begin < 3)
		leap_summ++;
	// если конечный год високосный и дата не раньше 1 марта, то учитываем, что он високосный
	if (isLeap(year_end) && month_end >= 3)
		leap_summ++;

	int difference = alldays_end - alldays_begin + 365 * (year_end - year_begin) + leap_summ;
	return difference;
}
void Show_day_report(multiset <Spending> report_spend_Wall,multiset <Spending> report_spend_Card, int size){     // Затраты за день
    multiset <Spending> rating;
    cout << "Day expenses report" << endl;
    unsigned day = 0;
    cout << "Enter day : "; cin >> day;
    for (auto elemSt : report_spend_Wall)
		{
			if (elemSt.GetDate().day == day)
				{
					rating.insert(elemSt);
				}
		}
    for (auto elemSp : report_spend_Card)
        {
            if (elemSp.GetDate().day == day)
				{
					rating.insert(elemSp);
				}
        }
    multiset<Spending>::iterator it;
		it = rating.begin();
		if (rating.size() < 3) size = rating.size();
		for (int i = 0; i < size; i++)
		{
			(*it).Output_Spending();
			it++;
		}
		cout << "Do you want to save the rating in the file? (yes - 1, no - 0)\n";
		bool yes;
		cin >> yes;
        if(!yes) return;
		ofstream out;
		out.open("Report_1.txt");
		it = rating.begin();
		if (out.is_open())
		{
			out << "Day :" << day << "\n";
			for (int i = 0; i < size; i++)
			{
				out << "Amount of money spending: " << it->Get_money() << "$" << endl
                << "Products : " << it->GetCategory().Products << "$" << endl
                << "Restaurants : " << it->GetCategory().Restaurants << "$" << endl
                << "Utilities : " << it->GetCategory().Utilities<< "$" << endl
                << "Entertainment : " << it->GetCategory().Entertainment<< "$" << endl
                << "Medecine : " << it->GetCategory().Medecine << "$" << endl;
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
void Show_week_report(multiset <Spending> report_spend_Wall,multiset <Spending> report_spend_Card, int size)
{
    cout << "Weekly expense report\n";
    time_t t = time(nullptr);
    tm* now = localtime(&t);

    multiset <Spending> rating;
    for (auto elemSt : report_spend_Wall)
		{
			if (elemSt.GetDate().month == (now->tm_mon + 1)
            && elemSt.GetDate().year == (now->tm_year + 1900))
				{
                    if (elemSt.GetDate().day <= (now->tm_mday+  7 )) rating.insert(elemSt);
                    else if (elemSt.GetDate().day <= (now->tm_mday+  14 )) rating.insert(elemSt);
                    else if (elemSt.GetDate().day <= (now->tm_mday+  21 )) rating.insert(elemSt);
                    else if (elemSt.GetDate().day <= (now->tm_mday+  28 )) rating.insert(elemSt);
				}
		}
    for (auto elemSp : report_spend_Card)
        {
            if (elemSp.GetDate().month == (now->tm_mon + 1)
            && elemSp.GetDate().year == (now->tm_year + 1900))
				{
                    if (elemSp.GetDate().day <= (now->tm_mday+  7 )) rating.insert(elemSp);
                    else if (elemSp.GetDate().day <= (now->tm_mday+  14 )) rating.insert(elemSp);
                    else if (elemSp.GetDate().day <= (now->tm_mday+  21 )) rating.insert(elemSp);
                    else if (elemSp.GetDate().day <= (now->tm_mday+  28 )) rating.insert(elemSp);
				}
        }
    multiset<Spending>::iterator it;
		it = rating.begin();
		if (rating.size() < 3) size = rating.size();
		for (int i = 0; i < size; i++)
		{
			(*it).Output_Spending();
			it++;
		}
		cout << "Do you want to save the rating in the file? (yes - 1, no - 0)\n";
		bool yes;
		cin >> yes;
        if(!yes) return;
		ofstream out;
		out.open("Report_2.txt");
		it = rating.begin();
		if (out.is_open())
		{
			out << "Weekly expense report" << endl;
			for (int i = 0; i < size; i++)
			{
				out << "Amount of money spending: " << it->Get_money() << "$" << endl
                << "Products : " << it->GetCategory().Products << "$" << endl
                << "Restaurants : " << it->GetCategory().Restaurants << "$" << endl
                << "Utilities : " << it->GetCategory().Utilities<< "$" << endl
                << "Entertainment : " << it->GetCategory().Entertainment<< "$" << endl
                << "Medecine : " << it->GetCategory().Medecine << "$" << endl;
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
void Show_month_report(multiset <Spending> report_spend_Wall,multiset <Spending> report_spend_Card, int size)
{
    multiset <Spending> rating;
		cout << "\nMonth expense report\n";
		unsigned month;
		cout << "Enter month: ";
		cin >> month;
		unsigned year;
		cout << "Enter year: ";
		cin >> year;
		for (auto elemSt : report_spend_Wall)
		{
			if (elemSt.GetDate().month == month && elemSt.GetDate().year == year)
				{
					rating.insert(elemSt);
				}
		}
        for (auto elemSp : report_spend_Card)
			{
				if (elemSp.GetDate().month == month && elemSp.GetDate().year == year)
				{
					rating.insert(elemSp);
				}
			}
		multiset<Spending>::iterator it;
		it = rating.begin();
		if (rating.size() < 3) size = rating.size();
		for (int i = 0; i < size; i++)
		{
			(*it).Output_Spending();
			it++;
		}
		cout << "Do you want to save the rating in the file? (yes - 1, no - 0)\n";
		bool yes;
		cin >> yes;
        if(!yes) return;
		ofstream out;
		out.open("Report_3.txt");
		it = rating.begin();
		if (out.is_open())
		{
			out << "Spendings for the month " << month << " of the year: " << year << "!\n";
			for (int i = 0; i < size; i++)
			{
				out << "Amount of money spending: " << it->Get_money() << "$" << endl
                << "Products : " << it->GetCategory().Products << "$" << endl
                << "Restaurants : " << it->GetCategory().Restaurants << "$" << endl
                << "Utilities : " << it->GetCategory().Utilities<< "$" << endl
                << "Entertainment : " << it->GetCategory().Entertainment<< "$" << endl
                << "Medecine : " << it->GetCategory().Medecine << "$" << endl;
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
void Monthly_report(multiset <Spending> report_spend_Wall,multiset <Spending> report_spend_Card)

{
        multiset <Spending> rating;
		cout << "\nMonth rating - Top 3 spendings!\n";
		unsigned month;
		cout << "Enter month number for the rating: ";
		cin >> month;
		unsigned year;
		cout << "Enter year for rating: ";
		cin >> year;
		for (auto elemSt : report_spend_Wall)
		{
			if (elemSt.GetDate().month == month && elemSt.GetDate().year == year)
				{
					rating.insert(elemSt);
				}
		}
        for (auto elemSp : report_spend_Card)
			{
				if (elemSp.GetDate().month == month && elemSp.GetDate().year == year)
				{
					rating.insert(elemSp);
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
        if(!yes) return;
		ofstream out;
		out.open("Report_4.txt");
		it = rating.begin();
		if (out.is_open())
		{
			out << "Top 3 spendings for the month " << month << " of the year: " << year << "!\n";
			for (int i = 0; i < size; i++)
			{
				out << "Amount of money spending: " << it->Get_money() << "$" << endl
                << "Products : " << it->GetCategory().Products << "$" << endl
                << "Restaurants : " << it->GetCategory().Restaurants << "$" << endl
                << "Utilities : " << it->GetCategory().Utilities<< "$" << endl
                << "Entertainment : " << it->GetCategory().Entertainment<< "$" << endl
                << "Medecine : " << it->GetCategory().Medecine << "$" << endl;
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
void Show_week_rating(multiset <Spending> report_spend_Wall,multiset <Spending> report_spend_Card)
{
        multiset <Spending> rating;
		cout << "\nMonth rating - Top 3 spendings!\n";
		unsigned month;
		cout << "Enter month number for the rating: ";
		cin >> month;
		unsigned year;
		cout << "Enter year for rating: ";
		cin >> year;
        time_t t = time(nullptr);
        tm* now = localtime(&t);
		for (auto elemSt : report_spend_Wall)
		{
			if (elemSt.GetDate().month == month && elemSt.GetDate().year == year)
				{
					if (elemSt.GetDate().day <= (now->tm_mday+  7 )) rating.insert(elemSt);
                    else if (elemSt.GetDate().day <= (now->tm_mday+  14 )) rating.insert(elemSt);
                    else if (elemSt.GetDate().day <= (now->tm_mday+  21 )) rating.insert(elemSt);
                    else if (elemSt.GetDate().day <= (now->tm_mday+  28 )) rating.insert(elemSt);
				}
		}
        for (auto elemSp : report_spend_Card)
			{
				if (elemSp.GetDate().month == month && elemSp.GetDate().year == year)
				{
					if (elemSp.GetDate().day <= (now->tm_mday+  7 )) rating.insert(elemSp);
                    else if (elemSp.GetDate().day <= (now->tm_mday+  14 )) rating.insert(elemSp);
                    else if (elemSp.GetDate().day <= (now->tm_mday+  21 )) rating.insert(elemSp);
                    else if (elemSp.GetDate().day <= (now->tm_mday+  28 )) rating.insert(elemSp);
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
        if(!yes) return;
		ofstream out;
		out.open("Report_5.txt");
		it = rating.begin();
		if (out.is_open())
		{
			out << "Top 3 spendings for the month " << month << " of the year: " << year << "!\n";
			for (int i = 0; i < size; i++)
			{
				out << "Amount of money spending: " << it->Get_money() << "$" << endl
                << "Products : " << it->GetCategory().Products << "$" << endl
                << "Restaurants : " << it->GetCategory().Restaurants << "$" << endl
                << "Utilities : " << it->GetCategory().Utilities<< "$" << endl
                << "Entertainment : " << it->GetCategory().Entertainment<< "$" << endl
                << "Medecine : " << it->GetCategory().Medecine << "$" << endl;
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