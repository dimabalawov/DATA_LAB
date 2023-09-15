#include "Data.h"
#include <iostream>

using namespace std;

Data::Data()
{
	day = 0;
	month = 0;
	year = 0;
}
Data::Data(int d, int m, int y)
{
	if ((d > 30 && (m != 4 && m != 6 && m != 9 && m != 11)) || (m == 2 && d > 28))
	{
		cout << "Wrong Date!" << endl;
		day = 0;
		month = 0;
		year = 0;
	}
	else
	{
		day = d;
		month = m;
		year = y;
	}
}

void Data::Input()
{
	int d, y, m;
	cout << "Enter the day: ";
	cin >> d;
	cout << "Enter the month: ";
	cin >> m;
	cout << "Enter the year: ";
	cin >> y;
	if ((d > 30 && (m == 4 || m == 6 || m == 9 || m == 11)) || (m == 2 && d > 28))
	{
		cout << "Wrong Date!" << endl;
		day = 0;
		month = 0;
		year = 0;
	}
	else
	{
		day = d;
		month = m;
		year = y;
	}
	 
}
void Data::Print()
{
	cout << "Day: " << day << "  Month: " << month << "  Year: " << year;
	cout << endl;
}
//setters, getters
int Data::getDay() const
{
	return day;
}
int Data::getMonth() const
{
	return month;
}
int Data::getYear() const
{
	return year;
}

void Data::setDay(int a)
{
	if ((a > 30 && (month != 4 && month != 6 && month != 9 && month != 11)) || (month == 2 && a > 28))
	{
		cout << "Wrong Date!" << endl;
		return;
	}
	else
		day = a;
}
void Data::setMonth(int m)
{
	if ((day > 30 && (m != 4 && m != 6 && m != 9 && m != 11)) || (m == 2 && day > 28))
	{
		cout << "Wrong Date!" << endl;
		return;
	}
	else
		month = m;
}
void Data::setYear(int y)
{
	year = y;
}
//operators
Data& Data::operator++()
{
	if (day == 30 && (month == 4 || month == 6 || month == 9 || month == 11))
	{
		day = 1;
		++month;
	}
	else if (day==31 && month == 12)
	{
		day = 1;
		month = 1;
		++year;
	}
	else if (day == 28 && month == 2)
	{
		day = 1;
		month = 3;
	}
	else
		++day;
	return *this;
}
Data& Data::operator--()
{
	if (day == 1)
	{
		if (month == 5 || month == 7 || month == 10 || month == 12)
		{
			day = 30;
			--month;
		}
		else if (month == 3)
		{
			--month;
			day = 28;
		}
		else if (month == 1)
		{
			--year;
			day = 31;
			month = 12;
		}
		else
		{
			day = 30;
			--month;
		}
	}
	else
		--day;
	return *this;
}
Data& Data::operator++(int a)
{
	Data b = *this;
	if (day == 30 && (month == 4 || month == 6 || month == 9 || month == 11))
	{
		day = 1;
		++month;
	}
	else if (day == 31 && month == 12)
	{
		day = 1;
		month = 1;
		++year;
	}
	else if (day == 28 && month == 2)
	{
		day = 1;
		month = 3;
	}
	else
		++day;
	return b;
}
Data& Data::operator--(int a)
{
	Data b = *this;
	if (day == 1)
	{
		if (month == 5 || month == 7 || month == 10 || month == 12)
		{
			day = 30;
			--month;
		}
		else if (month == 3)
		{
			--month;
			day = 28;
		}
		else if (month == 1)
		{
			--year;
			day = 31;
			month = 12;
		}
		else
		{
			day = 30;
			--month;
		}
	}
	else
		--day;
	return b;
}
Data& Data::operator+=(int a)
{
	while (a > 0)
	{
		if (day == 30 && (month == 4 || month == 6 || month == 9 || month == 11))
		{
			day = 1;
			++month;
		}
		else if (day == 31 && month == 12)
		{
			day = 1;
			month = 1;
			++year;
		}
		else if (day == 28 && month == 2)
		{
			day = 1;
			month = 3;
		}
		else
			++day;
		--a;
	}
	return *this;
}
Data& Data::operator-=(int a)
{
	while (a > 0)
	{
		if (day == 1)
		{
			if (month == 5 || month == 7 || month == 10 || month == 12)
			{
				day = 30;
				--month;
			}
			else if (month == 3)
			{
				--month;
				day = 28;
			}
			else if (month == 1)
			{
				--year;
				day = 31;
				month = 12;
			}
			else
			{
				day = 30;
				--month;
			}
		}
		else
			--day;
		--a;
	}
	return *this;
}
Data Data::operator+(int d)
{
	Data b = *this;
	while (d > 0)
	{
		if (b.day == 30 && (b.month == 4 || b.month == 6 || b.month == 9 || b.month == 11))
		{
			b.day = 1;
			++b.month;
		}
		else if (b.day == 31 && b.month == 12)
		{
			b.day = 1;
			b.month = 1;
			++b.year;
		}
		else if (b.day == 28 && b.month == 2)
		{
			b.day = 1;
			b.month = 3;
		}
		else
			++b.day;
		--d;
	}
	return b;
}

Data Data::operator-(int d)
{
	Data b = *this;
	while (d > 0)
	{
		if (b.day == 1)
		{
			if (b.month == 5 || b.month == 7 || b.month == 10 || b.month == 12)
			{
				b.day = 30;
				--b.month;
			}
			else if (b.month == 3)
			{
				--b.month;
				b.day = 28;
			}
			else if (b.month == 1)
			{
				--b.year;
				b.day = 31;
				b.month = 12;
			}
			else
			{
				b.day = 30;
				--b.month;
			}
		}
		else
			--b.day;
		--d;
	}
	return b;
}
Data Data::operator-(Data t)
{
	Data b = *this;
	int d = t.day;
	while (d > 0)
	{
		if (b.day == 1)
		{
			if (b.month == 5 || b.month == 7 || b.month == 10 || b.month == 12)
			{
				b.day = 30;
				--b.month;
			}
			else if (b.month == 3)
			{
				--b.month;
				b.day = 28;
			}
			else if (b.month == 1)
			{
				--b.year;
				b.day = 31;
				b.month = 12;
			}
			else
			{
				b.day = 30;
				--b.month;
			}
		}
		else
			--b.day;
		--d;
	}
	return b;
}

bool Data::operator>(Data& b)
{
	if (year > b.year)
		return true;
	if (year == b.year && month > b.month)
		return true;
	if (year == b.year && month == b.month && day>b.day)
		return true;
	return false;
}
bool Data::operator<(Data& b)
{
	if (year < b.year)
		return true;
	if (year == b.year && month < b.month)
		return true;
	if (year == b.year && month == b.month && day < b.day)
		return true;
	return false;
}
bool Data::operator>=(Data& b)
{
	if (year > b.year)
		return true;
	if (year == b.year && month > b.month)
		return true;
	if (year == b.year && month == b.month && day >= b.day)
		return true;
	return false;
}
bool Data::operator<=(Data& b)
{
	if (year < b.year)
		return true;
	if (year == b.year && month < b.month)
		return true;
	if (year == b.year && month == b.month && day <= b.day)
		return true;
	return false;
}
bool Data::operator==(Data& b)
{
	if (day == b.day && month == b.month && year == b.year)
		return true;
	return false;
}
bool Data::operator!=(Data& b)
{
	if (day == b.day && month == b.month && year == b.year)
		return false;
	return true;
}