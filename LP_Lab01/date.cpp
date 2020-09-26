#include <iostream>
using namespace std;

int month_length[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

bool is_date_correct(int date) {
	int min_date = 1000000, max_date = 99999999;
	if (date < min_date || date > max_date) return false;
	else return true;
}

bool is_year_correct(int year) {
	int min_year = 0, max_year = 2020;
	if (year < min_year || year > max_year) return false;
	else return true;
}

bool visokosnyi(int num) {
	if (num % 4 == 0) return true;
	else return false;
}

bool is_month_correct(int month) {
	int min_month = 1, max_month = 12;
	if (month<min_month || month>max_month) return false;
	else return true;
}

bool is_day_correct(int day, int month) {
	const int min_day = 1;
	if (day < min_day || day > month_length[month - 1]) return false;
	else return true;
}

int count_days(int d, int m) {
	int number = d;
	for (int i = 0; i < m - 1; i++) {
		number += month_length[i];
	}
	return number;
}

int main()
{
	setlocale(LC_CTYPE, "Russian");
	int num, day, month, year, day_number;
	bool vis = false, is_correct;
	cout << "введите дату (ддммгггг): \n";
	cin >> num;
	is_correct = is_date_correct(num);
	switch (is_correct) {
	case true: {
		year = num % 10000;
		is_correct = is_year_correct(year);
		switch (is_correct) {
		case true: {
			vis = visokosnyi(year);
			if (vis == true) cout << "год високосный\n";
			else cout << "год не високосный\n";
			if (vis == true) month_length[1] = 29;
			month = num % 1000000 / 10000;
			is_correct = is_month_correct(month);
			switch (is_correct) {
			case true: {
				day = num / 1000000;
				is_correct = is_day_correct(day, month);
				switch (is_correct) {
				case true: {
					day_number = count_days(day, month);
					cout << "порядковый номер дня в году: " << day_number << endl;
				} break;
				case false: cout << "некорректный день\n"; break;
				}
			} break;
			case false: cout << "некорректный месяц\n"; break;
			}
		} break;
		case false:	cout << "некорректный год\n"; break;
		}
	} break;
	case false: cout << "некорректный формат даты\n"; break;
	}
	system("pause");
	return 0;
}
