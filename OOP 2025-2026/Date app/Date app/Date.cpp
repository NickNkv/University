#include "Date.h"
#include <exception>

//lifecycle
Date::Date() {
	day = 1;
	month = 1;
	year = 1;
}

Date::Date(unsigned day, unsigned month, unsigned year) {
	if (year == 0) {
		throw std::invalid_argument("Invalid year");
	}
	if (month < 1 || month > 12) {
		throw std::invalid_argument("Invalid month");
	}
	if (day == 0 || day > daysInMonth(month, year)) {
		throw std::invalid_argument("Invalid day");;
	}

	this->day = day;
	this->month = month;
	this->year = year;
}

bool Date::setDate(unsigned day, unsigned month, unsigned year)
{
	if (year == 0) {
		return false;;
	}
	if (month < 1 || month > 12) {
		return false;
	}
	if (day == 0 || day > daysInMonth(month, year)) {
		return false;;
	}

	this->day = day;
	this->month = month;
	this->year = year;
}

unsigned Date::dayOfTheWeek() {
	unsigned tempY = this->year;
	unsigned tempM = this->month;
	unsigned tempD = this->day;

	if (tempM < 3) {
		tempM += 12;
		tempY--; 
	}
	unsigned k = tempY % 100;
	unsigned j = tempY / 100;
	unsigned h = (tempD + (13 * (tempM + 1)) / 5 + k + k / 4 + j / 4 + 5 * j) % 7;
	return ((h + 5) % 7) + 1;
}

int Date::daysInBetween(const Date& a, const Date& b)
{
	return numberOfDays(a) - numberOfDays(b);
}

int Date::dateCompare(const Date& first, const Date& second)
{
	if (first.day == second.day && first.month == second.month && first.year == second.year) {
		return 0;
	}

	if (first.year > second.year) {
		return 1;
	}
	if (first.year < second.year) {
		return -1;
	}

	if (first.month > second.month) {
		return 1;
	}
	if (first.month < second.month) {
		return -1;
	}

	if (first.day > second.day) {
		return 1;
	}
	else {
		return -1;
	}
}

void Date::addDays(int days)
{
	if (days > 0) {
		for (int i = 0; i < days; i++) {
			if (this->day == daysInMonth(this->month, this->year)) {
				this->day = 1;
				if (this->month == 12) {
					this->month = 1;
					this->year += 1;
				}
				else {
					this->month += 1;
				}
			}
			else {
				this->day += 1;
			}
		}
	}
	else {
		for (int i = days; i < 0; i++) {
			if (this->day == 1) {
				if (this->month == 1) {
					this->month = 12;
					this->year -= 1;
					this->day = 31;
				}
				else {
					this->month -= 1;
					this->day = daysInMonth(this->month, this->year);
				}
			}
			else {
				this->day -= 1;
			}
		}
	}
}

void Date::print() const
{
	std::cout << this->day << "/" << this->month << "/" << this->year << "\n";
}

//private methods
unsigned Date::daysInMonth(unsigned month, unsigned year)
{
	if (month == 0 || month > 12) {
		//invalid month
		return 0;
	}

	if (month == 2) {
		if (isLeapYear(year)) {
			return 29;
		}
		else {
			return 28;
		}
	}
	else if (month == 1 || month == 3 || month == 5 || month == 7 ||
			 month == 8 || month == 10 || month == 12) {
		return 31;
	}
	else {
		return 30;
	}
}

bool Date::isLeapYear(unsigned year)
{
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int Date::numberOfDays(const Date& a)
{
	int y = a.year, m = a.month, d = a.day;
	if (m < 3) { y--; m += 12; }
	return 365 * y + y / 4 - y / 100 + y / 400 + (153 * m - 457) / 5 + d - 306;
}
