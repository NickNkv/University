#define _CRT_SECURE_NO_WARNINGS
#include "Car.h"

//lifecycle

Car::Car(const char* model, const char* brand, const Date& date, unsigned color)
{
	this->model = new char[strlen(model) + 1];
	this->brand = new (std::nothrow) char[strlen(brand) + 1];

	if (!this->brand) {
		delete[] this->model;
		throw std::bad_alloc();
	}

	if (!validateColor(color)) {
		delete[] this->model;
		delete[] this->brand;
		throw std::invalid_argument("Color must be in RGB format!");
	}

	strcpy(this->model, model);
	strcpy(this->brand, brand);
	this->date = date;
	this->color = color;
	this->owner = nullptr;
}

Car::Car(const char* model, const char* brand, const Date& date, unsigned color, const Person& owner)
{
	this->model = new char[strlen(model) + 1];
	this->brand = new (std::nothrow) char[strlen(brand) + 1];

	if (!this->brand) {
		delete[] this->model;
		throw std::bad_alloc();
	}
	
	try {
		this->owner = new Person(owner);
	}
	catch (...) {
		delete[] this->model;
		delete[] this->brand;
		throw;
	}

	if (!validateColor(color)) {
		delete[] this->model;
		delete[] this->brand;
		throw std::invalid_argument("Color must be in RGB format!");
	}

	strcpy(this->model, model);
	strcpy(this->brand, brand);
	this->date = date;
	this->color = color;
}

Car::Car(const Car& other) : Car(other.model, other.brand, other.date, other.color)
{
	if (other.owner) {
		try {
			this->owner = new Person(*other.owner);
		}
		catch (...) {
			delete[] this->model;
			this->model = nullptr;
			delete[] this->brand;
			this->brand = nullptr;
			throw;
		}
	}
}

Car::~Car()
{
	delete[] this->model;
	delete[] this->brand;
}

//setters
bool Car::setColor(unsigned int newColor)
{
	if (!validateColor(newColor)) {
		return false;
	}

	this->color = newColor;
	return true;
}

bool Car::setOwner(const Person& newOwner)
{
	Person* temp = nullptr;
	try {
		temp = new Person(newOwner);
	}
	catch (...) {
		return false;
	}

	delete this->owner;
	this->owner = temp;
	temp = nullptr;
	return true;
}

void Car::print()
{
	std::cout << this->model << "\n" << this->brand << "\n";
	(this->date).print();
	std::cout << this->color << "\n";
	if (!this->owner) {
		std::cout << "No owner\n";
	}
	else {
		(*this->owner).print();
	}
}

//private
bool Car::validateColor(unsigned int color)
{
	unsigned int mask = 255 << 24;
	if (color & mask) {
		return false;
	}
	return true;
}
