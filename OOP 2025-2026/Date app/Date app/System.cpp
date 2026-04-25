#include "System.h"

System::System()
{
	this->cars = new Car*[MAX_MEMORY];
	this->people = new (std::nothrow) Person*[MAX_MEMORY];

	if (!this->people) {
		delete[] this->cars;
		throw std::bad_alloc();
	}

	this->carsCount = 0;
	this->peopleCount = 0;

	for (unsigned i = 0; i < MAX_MEMORY; i++) {
		this->cars[i] = nullptr;
		this->people[i] = nullptr;
	}
}

System::System(const Car& car, const Person& person) : System()
{
	this->cars[0] = new Car(car);
	try {
		this->people[0] = new Person(person); // new and copy constr of person may throw bad alloc
	}
	catch (...) {
		std::cout << "CATCH CALLED\n";
		delete this->cars[0];
		this->cars[0] = nullptr;
		throw;
	}

	this->carsCount = 1;
	this->peopleCount = 1;
}

System::System(const System& other) : System()
{
	if (other.carsCount > MAX_MEMORY || other.peopleCount > MAX_MEMORY) {
		throw std::runtime_error("Copying cars and people form larger collection to a smaller one");
	}

	try {
		for (unsigned i = 0; i < other.carsCount; i++) {
			this->cars[i] = new Car(*other.cars[i]);
			this->carsCount++;
		}
		for (unsigned i = 0; i < other.peopleCount; i++) {
			this->people[i] = new Person(*other.people[i]);
			this->peopleCount++;
		}
	}
	catch(...){
		for (unsigned i = 0; i < this->carsCount; i++) {
			delete this->cars[i];
			this->cars[i] = nullptr;
		}
		for (unsigned i = 0; i < this->peopleCount; i++) {
			delete this->people[i];
			this->people[i] = nullptr;
		}
		throw;
	}
}

System::~System()
{
	for (unsigned i = 0; i < this->carsCount; i++) {
		delete this->cars[i];
		this->cars[i] = nullptr;
	}
	delete[] this->cars;
	this->cars = nullptr;

	for (unsigned i = 0; i < this->peopleCount; i++) {
		delete this->people[i];
		this->people[i] = nullptr;
	}
	delete[] this->people;
	this->people = nullptr;
}

bool System::addCar(const Car& car)
{
	if (this->carsCount >= MAX_MEMORY) {
		return false;
	}

	try {
		this->cars[this->carsCount] = new Car(car);
		this->carsCount++;
	}
	catch (...) {
		return false;
	}

	return true;
}

bool System::addPerson(const Person& person)
{
	if (this->peopleCount >= MAX_MEMORY) {
		return false;
	}

	try {
		this->people[this->peopleCount] = new Person(person);
		this->peopleCount++;
	}
	catch (...) {
		return false;
	}

	return true;
}

unsigned System::countPeopleWithMultipleCars()
{
	unsigned count = 0;
	for (unsigned i = 0; i < this->peopleCount; i++) {
		if (!this->people[i]) {
			continue;
		}
		if (ownedCars(*this->people[i]) > 1) {
			count++;
		}
	}
	return count;
}

unsigned System::countCarsWithoutOwner()
{
	unsigned count = 0;
	for (unsigned i = 0; i < this->carsCount; i++) {
		if (this->cars[i]->getOwner() == nullptr) {
			count++;
		}
	}

	return count;
}

void System::printCarsOwnerBy(const Person& p)
{
	std::cout << "Cars owned by " << p.getName() << " " << p.getLastName() << "\n";
	bool flag = true;
	for (unsigned i = 0; i < this->carsCount; i++) {
		if (!this->cars[i]->getOwner()) {
			continue;
		}
		if (p.isSamePerson(*this->cars[i]->getOwner())) {
			this->cars[i]->print();
			flag = false;
		}
	}
	if (flag) {
		std::cout << "This person does not have any cars\n\n";
	}
}

void System::printPeopleWithCars(unsigned numberOfCars)
{
	std::cout << "People with " << numberOfCars << " cars\n";
	bool flag = true;
	for (unsigned i = 0; i < this->peopleCount; i++) {
		if (ownedCars(*this->people[i]) == numberOfCars) {
			this->people[i]->print();
			flag = false;
		}
	}
	if (flag) {
		std::cout << "none\n\n";
	}
}

void System::printCars()
{
	for (unsigned i = 0; i < this->carsCount; i++) {
		this->cars[i]->print();
		std::cout << "\n\n";
	}
}

unsigned System::ownedCars(const Person& person)
{
	unsigned count = 0;
	for (unsigned i = 0; i < this->carsCount; i++) {
		if (!this->cars[i]->getOwner()) {
			continue;
		}
		if (person.isSamePerson(*this->cars[i]->getOwner())) {
			count++;
		}
	}

	return count;
}
