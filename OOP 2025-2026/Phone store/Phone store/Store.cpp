#define _CRT_SECURE_NO_WARNINGS
#define ALLOC_STEP 5
#include "Store.hpp"
#include <iostream>

Store::Store(double budget) : budget(budget), phones(nullptr), spent(0), count(0), allocated(ALLOC_STEP)
{
	validateBudget(budget);

	this->phones = new Phone*[this->allocated];

	for (size_t i = 0; i < this->allocated; i++) {
		this->phones[i] = nullptr;
	}
}

Store::Store(const Store& other) : budget(other.budget), phones(nullptr), spent(other.spent), count(other.count), allocated(other.allocated)
{
	this->phones = new Phone * [this->allocated];
	for (size_t i = 0; i < this->allocated; i++) {
		if (!other.phones[i]) {
			this->phones[i] = nullptr;
			continue;
		}

		try {
			this->phones[i] = other.phones[i]->clone();
		}
		catch (...) {
			for (size_t j = 0; j < i; j++) {
				delete this->phones[j];
				this->phones[j] = nullptr;
			}
			delete[] this->phones;
			this->phones = nullptr;
			throw;
		}
	}
}

Store::~Store()
{
	if (this->phones) {
		for (size_t i = 0; i < this->allocated; i++) {
			delete this->phones[i];
			this->phones[i] = nullptr;
		}
	}
	delete[] this->phones;
	this->phones = nullptr;
}

bool Store::addPhone(const Phone& phone)
{
	if (this->spent + phone.getPrice() > this->budget) {
		throw "Insufficient budget!";
	}

	if (this->count == this->allocated) {
		resize();
	}

	for (size_t i = 0; i < this->allocated; i++) {
		if (this->phones[i] == nullptr) {
			this->phones[i] = phone.clone();
			break;
		}
	}

	this->spent += phone.getPrice();
	this->count++;
	return true;
}

void Store::print()
{
	if (!this->phones) {
		std::cout << "The store is empty";
		return;
	}

	for (size_t i = 0; i < this->allocated; i++) {
		if (this->phones[i]) {
			this->phones[i]->print();
			std::cout << "\n";
		}
	}
}

void Store::resize()
{
	Phone** tempPhones = new Phone * [this->allocated + ALLOC_STEP];
	for (size_t i = 0; i < this->allocated; i++) {
		if (!this->phones[i]) {
			tempPhones[i] = nullptr;
			continue;
		}
		try {
			tempPhones[i] = this->phones[i]->clone();
		}
		catch (...) {
			for (size_t j = 0; j < i; j++) {
				delete tempPhones[i];
				tempPhones[i] = nullptr;
			}
			delete[] tempPhones;
			throw;
		}
	}
	for (size_t i = this->allocated; i < this->allocated + ALLOC_STEP; i++) {
		tempPhones[i] = nullptr;
	}

	for (size_t i = 0; i < this->allocated; i++) {
		delete this->phones[i];
		this->phones[i] = nullptr;
	}
	delete[] this->phones;

	this->phones = tempPhones;
	this->allocated += ALLOC_STEP;
}


//helpers
double Store::validateBudget(double budget) {
	if (budget <= 0) {
		throw std::invalid_argument("Budget must be a positive number!");
	}

	return budget;
}