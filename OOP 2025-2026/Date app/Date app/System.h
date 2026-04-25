#pragma once
#include "Car.h"
#include "Person.h"
#define MAX_MEMORY 10

class System {
public:
	//lifecycle
	System();
	System(const Car& car, const Person& person);
	System(const System& other);
	~System();

	//methods
	bool addCar(const Car& car);
	bool addPerson(const Person& person);

	unsigned countPeopleWithMultipleCars();
	unsigned countCarsWithoutOwner();
	void printCarsOwnerBy(const Person& p);
	void printPeopleWithCars(unsigned numberOfCars);

	void printCars();

private:
	unsigned ownedCars(const Person& person);

private:
	unsigned carsCount;
	unsigned peopleCount;
	Car** cars;
	Person** people;
};