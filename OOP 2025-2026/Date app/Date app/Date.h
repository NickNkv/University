#pragma once

#include <iostream>

class Date {
public:
	//ctor and dtor
	Date();
	Date(unsigned day, unsigned month, unsigned year);
	Date(const Date& other) = default;
	~Date() = default;

	//getters and setters
	unsigned getDay() const { return day; }
	unsigned getMonth() const { return month; }
	unsigned getYear() const { return year; }

	bool setDate(unsigned day, unsigned month, unsigned year);

	//util
	unsigned dayOfTheWeek(); //Zeller's Congruence
	static int daysInBetween(const Date& a, const Date& b);
	static int dateCompare(const Date& first, const Date& second);
	void addDays(int days);
	void print() const;

private:
	unsigned daysInMonth(unsigned month, unsigned year);
	bool isLeapYear(unsigned year);
	static int numberOfDays(const Date& a);

private:
	unsigned int day;
	unsigned int month;
	unsigned int year;
};