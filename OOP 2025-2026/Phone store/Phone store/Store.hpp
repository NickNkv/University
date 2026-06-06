#pragma once
#include "Phone.hpp"

class Store {
public:
	Store() = delete;
	Store(double budget);
	Store(const Store& other);
	Store& operator = (const Store& other) = delete;
	~Store();

	bool addPhone(const Phone& phone);
	void sell(const char* model, const char* brand);
	size_t getPhoneCount() const { return count; }
	double getBudget() const { return budget; }
	double getRemainingBudget() const { return budget - spent; }

	void print();

private:
	const double budget;
	Phone** phones;
	double spent; //price of all the phones in the store
	size_t count; //number of phones in the store
	size_t allocated; //allocated space

private:
	void resize();
	double validateBudget(double budget);
};