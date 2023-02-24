#include <iostream>
#include <iomanip>

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
            << "Utilities = " << Utilities << endl << endl;
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
        cout << "Enter day of spending:"; cin >> day;
        cout << "Enter month of spending:"; cin >> month;
        cout << "Enter year of spending:"; cin >> year;
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
        cout << "Enter hours of spending:"; cin >> hours;
        cout << "Enter minutes of spending:"; cin >> minutes;
        cout << "Enter seconds of spending:"; cin >> seconds;
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

int diff_between_dates(Date begin_date, Date end_date) // функция, определяющая количество дней между 2-мя датами
{                                                       // эта функция нужна для отображения дел за неделю
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
