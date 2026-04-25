#pragma once
#include <iostream>
#include "Date.h"
#include "Person.h"

class Car {
public:
	Car() = delete;
	Car(const char* model, const char* brand, const Date& date, unsigned color);
	Car(const char* model, const char* brand, const Date& date, unsigned color, const Person& owner);
	Car(const Car& other);
	~Car();

	//getters and setters
	const char* getModel() const { return model; }
	const char* getBrand() const { return brand; }
	const Date& getDate() const { return date; }

	unsigned int getColor() const { return color; }
	bool setColor(unsigned int newColor);

	const Person* getOwner() const { return owner; }
	bool setOwner(const Person& newOwner);
	 
	//methods
	void print();

private:
	char* model;
    char* brand;
	Date date;
	unsigned int color;
	Person* owner;

	bool validateColor(unsigned int color);
};