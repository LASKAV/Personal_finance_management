#include <iostream>
#include <iomanip>
#include <set>
#include <fstream>
#include <ctime>
#include <unordered_map>
#include <map>
#include <vector>
#include "Category.h"
#include "Date.h"
#include "Time.h"
#include "Spending.h"
#include "MoneyStorage.h"
#include "Card.h"
#include "Wallet.h"

using namespace std;


void line();
void Show_day_report(multiset <Spending> report_spend_Wall,multiset <Spending> report_spend_Card);
void Show_week_report(multiset<Spending> report_spend_Wall, multiset<Spending> report_spend_Card);
void Show_month_report(multiset<Spending> report_spend_Wall,multiset<Spending>report_spend_Card);
void Show_week_rating(multiset<Spending> report_spend_Wall, multiset<Spending> report_spend_Card);
void Monthly_report(multiset <Spending> report_spend_Wall,multiset <Spending> report_spend_Card);
void Show_week_categories(multiset<Spending> report_spend_Wall, multiset<Spending> report_spend_Card);
void Monthly_report_categories(multiset <Spending> report_spend_Wall,multiset <Spending> report_spend_Card);

int main()
{
     Spending* spendings_Card[11];
     Spending* spendings_Wall[11];
     multiset<Spending> report_spend_Wall;
     multiset<Spending> report_spend_Card;
     int choice_сreation = 0;
     int num_card = 0;
     int num_wall = 0;
     short num_spend_card = 0;
     short num_spend_wall = 0;
     short choice_ = 0;
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
                       cout << "Enter card number : "; cin >> choice_;
                       OBJ_Card[choice_]->OutPut();
                       spendings_Card[choice_] = new Spending;
                       spendings_Card[choice_]->input_Spen();
                       meny_spend += spendings_Card[choice_]->Get_money();
                       OBJ_Card[choice_]->Spend_money(meny_spend);
                       spendings_Card[choice_]->Output_Spending();
                       report_spend_Card.insert(*spendings_Card[choice_]);
                       num_spend_card+=choice_;
                     break;
                 case 2:
                         for (int i = 1; i < num_wall + 1; i++)
                        {
                            cout << "Wall #" << i << ' '; OBJ_Wall[i]->OutPut(); cout << endl;
                        }
                       cout << "Enter wall number : "; cin >> choice_;
                       OBJ_Wall[choice_]->OutPut();
                       spendings_Wall[choice_] = new Spending;
                       spendings_Wall[choice_]->input_Spen();
                       meny_spend += spendings_Wall[choice_]->Get_money();
                       OBJ_Wall[choice_]->Spend_money(meny_spend);
                       spendings_Wall[choice_]->Output_Spending();
                       report_spend_Wall.insert(*spendings_Wall[choice_]);
                       num_spend_wall+=choice_;
                     break;
                 case 3:
                     line();
                     for (int i = 0; i < num_spend_card; ++i)
                     {
                        cout << endl << "Card #" << i << " spend"; spendings_Card[i]->Output_Spending();
                     }
                     line();
                     for (int i = 0; i < num_spend_wall; ++i)
                     {
                        cout << endl << "Wall #" << i << " spend"; spendings_Wall[i]->Output_Spending();
                     }
                     line();
                     break;
                 default:
                     cout << "Invalid choice!\n";
                     break;
             }
         } while (true);
            break;

     case 4:  // Затраты за день
         Show_day_report(report_spend_Wall,report_spend_Card);
        break;
     case 5:  // Затраты за неделю
        Show_week_report(report_spend_Wall,report_spend_Card);
         break;
     case 6:  // Затраты за месяц
            Show_month_report(report_spend_Wall,report_spend_Card);
         break;
     case 7:  // ТОП-3 затрат за неделю
            Show_week_rating(report_spend_Wall,report_spend_Card);
         break;
     case 8:  // ТОП-3 затрат за месяц
            Monthly_report(report_spend_Wall,report_spend_Card);
         break;
     case 9:  // ТОП-3 категорий за неделю
            Show_week_categories(report_spend_Wall,report_spend_Card);
         break;
     case 10:  // ТОП-3 категорий за месяц
            Monthly_report_categories(report_spend_Wall,report_spend_Card);
         break;
     case 11:
         return 0;
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
void Show_day_report(multiset <Spending> report_spend_Wall,multiset <Spending> report_spend_Card){     // Затраты за день
   Date day;
   day.Input();
   cout << "Show day report " << endl;
    multiset<Spending> rating;
    for (const auto& elemSt : report_spend_Wall)
    {
        if (elemSt.GetDate().day == day.day &&
            elemSt.GetDate().month == day.month &&
            elemSt.GetDate().year == day.year)
        {
            rating.insert(elemSt);
        }
    }
    for (const auto& elemSp : report_spend_Card)
    {
        if (elemSp.GetDate().day == day.day &&
            elemSp.GetDate().month == day.month &&
            elemSp.GetDate().year == day.year)
        {
            rating.insert(elemSp);
        }
    }

    multiset<Spending>::iterator it;
    it = rating.begin();
    for (; it != rating.end(); ++it)
    {
        it->Output_Spending();
    }

    cout << "\nDo you want to save the rating in the file? (yes - 1, no - 0)\n";
    bool yes;
    cin >> yes;
    if (!yes) return;

    ofstream out;
    out.open("Show_day_report.txt");
    if (out.is_open())
    {
        out << "Expense report for " << endl;
        day.Output();
        for (it = rating.begin(); it != rating.end(); ++it)
        {
            out << "Amount of money spending: " << it->Get_money() << "$" << endl
                << "Products : " << it->GetCategory().Products << "$" << endl
                << "Restaurants : " << it->GetCategory().Restaurants << "$" << endl
                << "Utilities : " << it->GetCategory().Utilities << "$" << endl
                << "Entertainment : " << it->GetCategory().Entertainment << "$" << endl
                << "Medecine : " << it->GetCategory().Medecine << "$" << endl;
            out << "Date of transaction: " << setw(2) << setfill('0')
                << it->GetDate().day << '/' << setw(2) << setfill('0')
                << it->GetDate().month << '/' << setw(2) << setfill('0')
                << it->GetDate().year << "\n";
            out << "Time of transaction: " << setw(2) << setfill('0')
                << it->GetTime().hours << ':' << setw(2) << setfill('0')
                << it->GetTime().minutes << ':' << setw(2) << setfill('0')
                << it->GetTime().seconds << "\n\n";
        }
    }
}
void Show_week_report(multiset<Spending> report_spend_Wall, multiset<Spending> report_spend_Card)
{
    cout << "Weekly expense report\n";
    Date start_date;
    start_date.Input();
    Date end_date;
    end_date.Input();
    multiset<Spending> rating;
    for (auto elemSt : report_spend_Wall)
    {
        // Проверяем, что дата трат находится в интервале от start_date до end_date
        if (elemSt.GetDate().year >= start_date.year && elemSt.GetDate().year <= end_date.year &&
            elemSt.GetDate().month >= start_date.month && elemSt.GetDate().month <= end_date.month &&
            elemSt.GetDate().day >= start_date.day && elemSt.GetDate().day <= end_date.day)
        {
            rating.insert(elemSt);
        }
    }
    for (auto elemSp : report_spend_Card)
    {
        if (elemSp.GetDate().year >= start_date.year && elemSp.GetDate().year <= end_date.year &&
            elemSp.GetDate().month >= start_date.month && elemSp.GetDate().month <= end_date.month &&
            elemSp.GetDate().day >= start_date.day && elemSp.GetDate().day <= end_date.day)
        {
            rating.insert(elemSp);
        }
    }

    multiset<Spending>::iterator it;
    it = rating.begin();
    for (; it != rating.end(); ++it)
    {
        it->Output_Spending();
    }
    cout << "\nDo you want to save the rating in the file? (yes - 1, no - 0)\n";
    bool yes;
    cin >> yes;
    if (!yes) return;
    ofstream out;
    out.open("Show_week_report.txt");
    if (out.is_open())
    {
        out << "Weekly expense report" << endl;
        for (;it != rating.end(); ++it)
        {
            out << "Amount of money spending: " << it->Get_money() << "$" << endl
                << "Products : " << it->GetCategory().Products << "$" << endl
                << "Restaurants : " << it->GetCategory().Restaurants << "$" << endl
                << "Utilities : " << it->GetCategory().Utilities << "$" << endl
                << "Entertainment : " << it->GetCategory().Entertainment << "$" << endl
                << "Medecine : " << it->GetCategory().Medecine << "$" << endl;
            out << "Date of transaction: "
                << setw(2) << setfill('0')
                << it->GetDate().day << '/' << setw(2) << setfill('0')
                << it->GetDate().month << '/' << setw(2) << setfill('0')
                << it->GetDate().year << "\n";
            out << "Time of transaction: " << setw(2) << setfill('0')
                << it->GetTime().hours << ':' << setw(2) << setfill('0')
                << it->GetTime().minutes << ':' << setw(2) << setfill('0')
                << it->GetTime().seconds << "\n\n";
            it++;
        }
    }
}
void Show_month_report(multiset<Spending> report_spend_Wall,multiset<Spending>report_spend_Card){
    Date  month_date;
    month_date.Input();
    cout << "Monthly expense report\n";

    multiset <Spending> rating;
    for (auto elemSt : report_spend_Wall)
    {
        if (elemSt.GetDate().month == month_date.month && elemSt.GetDate().year == month_date.year)
        {
            rating.insert(elemSt);
        }
    }
    for (auto elemSp : report_spend_Card)
    {
        if (elemSp.GetDate().month == month_date.month && elemSp.GetDate().year == month_date.year)
        {
            rating.insert(elemSp);
        }
    }
    multiset<Spending>::iterator it;
    it = rating.begin();
    for (; it != rating.end(); ++it)
    {
        it->Output_Spending();
    }

    cout << "\nDo you want to save the rating in the file? (yes - 1, no - 0)\n";
    bool yes;
    cin >> yes;
    if (!yes) return;
    ofstream out;
    out.open("Show_month_report.txt");
    if (out.is_open())
    {
        out << "Monthly expense report" << endl;
        for (; it != rating.end(); ++it)
        {
            out << "Amount of money spending: " << it->Get_money() << "$" << endl
                << "Products : " << it->GetCategory().Products << "$" << endl
                << "Restaurants : " << it->GetCategory().Restaurants << "$" << endl
                << "Utilities : " << it->GetCategory().Utilities << "$" << endl
                << "Entertainment : " << it->GetCategory().Entertainment << "$" << endl
                << "Medecine : " << it->GetCategory().Medecine << "$" << endl;
            out << "Date of transaction: "
                << setw(2) << setfill('0')
                << it->GetDate().day << '/' << setw(2) << setfill('0')
                << it->GetDate().month << '/' << setw(2) << setfill('0')
                << it->GetDate().year << "\n";
            out << "Time of transaction: " << setw(2) << setfill('0')
                << it->GetTime().hours << ':' << setw(2) << setfill('0')
                << it->GetTime().minutes << ':' << setw(2) << setfill('0')
                << it->GetTime().seconds << "\n\n";
            it++;
        }
    }
}
void Show_week_rating(multiset<Spending> report_spend_Wall, multiset<Spending> report_spend_Card)
{
    cout << "Weekly top 3 expense report\n";
    Date start_date;
    start_date.Input();
    Date end_date;
    end_date.Input();
    multiset<Spending> rating;
    for (auto elemSt : report_spend_Wall)
    {
        // Проверяем, что дата трат находится в интервале от start_date до end_date
        if (elemSt.GetDate().year >= start_date.year && elemSt.GetDate().year <= end_date.year &&
            elemSt.GetDate().month >= start_date.month && elemSt.GetDate().month <= end_date.month &&
            elemSt.GetDate().day >= start_date.day && elemSt.GetDate().day <= end_date.day)
        {
            rating.insert(elemSt);
        }
    }
    for (auto elemSp : report_spend_Card)
    {
        if (elemSp.GetDate().year >= start_date.year && elemSp.GetDate().year <= end_date.year &&
            elemSp.GetDate().month >= start_date.month && elemSp.GetDate().month <= end_date.month &&
            elemSp.GetDate().day >= start_date.day && elemSp.GetDate().day <= end_date.day)
        {
            rating.insert(elemSp);
        }
    }

    multiset<Spending>::iterator it = rating.begin();
    int count = 0;
    while (it != rating.end() && count < 3)
    {
        it->Output_Spending();
        cout << endl;
        it++;
        count++;
    }
     cout << "\nDo you want to save the rating in the file? (yes - 1, no - 0)\n";
    bool yes;
    cin >> yes;
    if (!yes) return;
    ofstream out;
    out.open("Show_week_rating.txt");
    if (out.is_open())
    {
        out << "Monthly expense report" << endl;
        for (int i = 0; i < 3; i++)
        {
            out << "Amount of money spending: " << it->Get_money() << "$" << endl
                << "Products : " << it->GetCategory().Products << "$" << endl
                << "Restaurants : " << it->GetCategory().Restaurants << "$" << endl
                << "Utilities : " << it->GetCategory().Utilities << "$" << endl
                << "Entertainment : " << it->GetCategory().Entertainment << "$" << endl
                << "Medecine : " << it->GetCategory().Medecine << "$" << endl;
            out << "Date of transaction: "
                << setw(2) << setfill('0')
                << it->GetDate().day << '/' << setw(2) << setfill('0')
                << it->GetDate().month << '/' << setw(2) << setfill('0')
                << it->GetDate().year << "\n";
            out << "Time of transaction: " << setw(2) << setfill('0')
                << it->GetTime().hours << ':' << setw(2) << setfill('0')
                << it->GetTime().minutes << ':' << setw(2) << setfill('0')
                << it->GetTime().seconds << "\n\n";
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
		cout << "\nDo you want to save the rating in the file? (yes - 1, no - 0)\n";
		bool yes;
		cin >> yes;
        if(!yes) return;
		ofstream out;
		out.open("Monthly_report.txt");
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
void Show_week_categories(multiset<Spending> report_spend_Wall, multiset<Spending> report_spend_Card)
{
    cout << "Weekly top 3 expense categories\n";
    Date start_date;
    start_date.Input();
    Date end_date;
    end_date.Input();
    multiset<Spending> rating;
    for (auto elemSt : report_spend_Wall)
    {
        // Проверяем, что дата трат находится в интервале от start_date до end_date
        if (elemSt.GetDate().year >= start_date.year && elemSt.GetDate().year <= end_date.year &&
            elemSt.GetDate().month >= start_date.month && elemSt.GetDate().month <= end_date.month &&
            elemSt.GetDate().day >= start_date.day && elemSt.GetDate().day <= end_date.day)
        {
            rating.insert(elemSt);
        }
    }
    for (auto elemSp : report_spend_Card)
    {
        if (elemSp.GetDate().year >= start_date.year && elemSp.GetDate().year <= end_date.year &&
            elemSp.GetDate().month >= start_date.month && elemSp.GetDate().month <= end_date.month &&
            elemSp.GetDate().day >= start_date.day && elemSp.GetDate().day <= end_date.day)
        {
            rating.insert(elemSp);
        }
    }
    multiset<Spending>::iterator it;
    it = rating.begin();
    int count = 0;
    while (it != rating.end() && count < 3)
    {
        it->Output_Spending();
        cout << endl;
        it++;
        count++;
    }
     cout << "\nDo you want to save the rating in the file? (yes - 1, no - 0)\n";
    bool yes;
    cin >> yes;
    if (!yes) return;
    ofstream out;
    out.open("Show_week_categories.txt");
    if (out.is_open())
    {
        out << "Monthly expense report" << endl;
        for (int i = 0; i < 3; i++)
        {
            out << "Amount of money spending: " << it->Get_money() << "$" << endl
                << "Products : " << it->GetCategory().Products << "$" << endl
                << "Restaurants : " << it->GetCategory().Restaurants << "$" << endl
                << "Utilities : " << it->GetCategory().Utilities << "$" << endl
                << "Entertainment : " << it->GetCategory().Entertainment << "$" << endl
                << "Medecine : " << it->GetCategory().Medecine << "$" << endl;
            out << "Date of transaction: "
                << setw(2) << setfill('0')
                << it->GetDate().day << '/' << setw(2) << setfill('0')
                << it->GetDate().month << '/' << setw(2) << setfill('0')
                << it->GetDate().year << "\n";
            out << "Time of transaction: " << setw(2) << setfill('0')
                << it->GetTime().hours << ':' << setw(2) << setfill('0')
                << it->GetTime().minutes << ':' << setw(2) << setfill('0')
                << it->GetTime().seconds << "\n\n";
            it++;
        }
    }
}
void Monthly_report_categories(multiset <Spending> report_spend_Wall,multiset <Spending> report_spend_Card)
{
    multiset <Spending> rating;
    cout << "\nMonth rating - Top 3 categories!\n";
    unsigned month;
    cout << "Enter month number for the rating: ";
    cin >> month;
    unsigned year;
    cout << "Enter year for rating: ";
    cin >> year;
    Category total;  // суммарные расходы по категориям за месяц
    for (auto elemSt : report_spend_Wall)
    {
        if (elemSt.GetDate().month == month && elemSt.GetDate().year == year)
        {
            total.Products += elemSt.GetCategory().Products;
            total.Restaurants += elemSt.GetCategory().Restaurants;
            total.Medecine += elemSt.GetCategory().Medecine;
            total.Entertainment += elemSt.GetCategory().Entertainment;
            total.Utilities += elemSt.GetCategory().Utilities;
        }
    }
    for (auto elemSp : report_spend_Card)
    {
        if (elemSp.GetDate().month == month && elemSp.GetDate().year == year)
        {
            total.Products += elemSp.GetCategory().Products;
            total.Restaurants += elemSp.GetCategory().Restaurants;
            total.Medecine += elemSp.GetCategory().Medecine;
            total.Entertainment += elemSp.GetCategory().Entertainment;
            total.Utilities += elemSp.GetCategory().Utilities;
        }
    }
    vector<pair<double, string>> sorted_categories;  // вектор пар (сумма расходов, категория), отсортированный по убыванию
    sorted_categories.push_back({total.Products, "Products"});
    sorted_categories.push_back({total.Restaurants, "Restaurants"});
    sorted_categories.push_back({total.Medecine, "Medecine"});
    sorted_categories.push_back({total.Entertainment, "Entertainment"});
    sorted_categories.push_back({total.Utilities, "Utilities"});
    sort(sorted_categories.rbegin(), sorted_categories.rend());
    unsigned size = 3;
    if (sorted_categories.size() < 3) size = sorted_categories.size();
    for (int i = 0; i < size; i++)
    {
        cout << sorted_categories[i].second << ": " << sorted_categories[i].first << "$" << endl;
    }
    cout << "\nDo you want to save the rating in the file? (yes - 1, no - 0)\n";
    bool yes;
    cin >> yes;
    if(!yes) return;
    ofstream out;
    out.open("Monthly_report_categories.txt");
    if (out.is_open())
    {
        out << "Top 3 categories for the month " << month << " of the year: " << year << "!\n";
        for (int i = 0; i < size; i++)
        {
            out << sorted_categories[i].second << ": " << sorted_categories[i].first << "$" << endl;
        }
    }
}