#define _CRT_SECURE_NO_WARNINGS
#include "Person.h"

//lifecycle
Person::Person(const char* name, const char* middleName, const char* lastName, const Date& birthDate, Gender gender)
	: name(nullptr), middleName(nullptr), lastName(nullptr), birthDate(birthDate), gender(gender)
{
	this->name = new char[strlen(name) + 1];

	this->middleName = new (std::nothrow) char[strlen(middleName) + 1];
	if (!this->middleName) {
		delete[] this->name;
		throw std::bad_alloc();
	}

	this->lastName = new (std::nothrow) char[strlen(lastName) + 1];
	if (!this->lastName) {
		delete[] this->name;
		delete[] this->middleName;
		throw std::bad_alloc();
	}

	strcpy(this->name, name);
	strcpy(this->middleName, middleName);
	strcpy(this->lastName, lastName);
}

Person::Person(const Person& other) : Person(other.name, other.middleName, other.lastName, other.birthDate, other.gender)
{
}

Person::~Person()
{
	delete[] this->name;
	delete[] this->middleName;
	delete[] this->lastName;
}

//setters
bool Person::setNames(const char* newName, const char* newMiddleName, const char* newLastName)
{
	if (strlen(newName) == 0 || strlen(newMiddleName) == 0 || strlen(newLastName)) {
		return false;
	}

	char* tName = new (std::nothrow) char[strlen(newName) + 1];
	if (!tName) {
		return false;
	}

	char* tMiddleName = new (std::nothrow) char[strlen(newMiddleName) + 1];
	if (!tMiddleName) {
		delete[] tName;
		return false;
	}

	char* tLastName = new (std::nothrow) char[strlen(newLastName) + 1];
	if (!tLastName) {
		delete[] tName;
		delete[] tMiddleName;
		return false;
	}

	//if OK
	strcpy(tName, newName);
	strcpy(tMiddleName, newMiddleName);
	strcpy(tLastName, newLastName);

	delete[] this->name;
	delete[] this->middleName;
	delete[] this->lastName;

	this->name = tName;
	this->middleName = tMiddleName;
	this->lastName = tLastName;

	return true;
}

bool Person::setLastName(const char* newLastName)
{
	if (strlen(newLastName) == 0) {
		return false;
	}

	char* temp = new (std::nothrow) char[strlen(newLastName) + 1];
	if (!temp) {
		return false;
	}

	strcpy(temp, newLastName);
	delete[] this->lastName;
	this->lastName = temp;
	return true;
}

//methods
void Person::print()
{
	std::cout << this->name << " " << this->middleName << " " << this->lastName << "\n";
	this->birthDate.print();
	std::cout << utils::getGender(this->gender) << "\n\n";
}

bool Person::isSamePerson(const Person& p) const
{
	bool flag = strcmp(this->name, p.name) == 0 && strcmp(this->middleName, p.middleName) == 0 &&
				strcmp(this->lastName, p.lastName) == 0 && Date::dateCompare(this->birthDate, p.birthDate) == 0 && this->gender == p.gender;
	return flag;
}
