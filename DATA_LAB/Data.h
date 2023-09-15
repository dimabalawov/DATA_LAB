#pragma once
class Data
{
private:
	int day;
	int month;
	int year;
public:
	Data();
	Data(int d, int m, int y);

	void Print();
	void Input();

	void setDay(int d);
	void setMonth(int m);
	void setYear(int y);
	int getDay() const;
	int getMonth() const;
	int getYear() const;

	Data& operator++();
	Data& operator--();
	Data& operator++(int a);
	Data& operator--(int a);
	Data& operator+=(int a);
	Data& operator-=(int a);

	Data operator+(int d);
	Data operator-(int d);
	Data operator-(Data b);

	bool operator>(Data& b);
	bool operator<(Data& b);
	bool operator>=(Data& b);
	bool operator<=(Data& b);
	bool operator==(Data& b);
	bool operator!=(Data& b);
};

