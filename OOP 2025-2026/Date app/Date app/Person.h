#pragma once
#include <iostream>
#include "EnumTypes.h"
#include "Date.h"
#include "utils.h"

class Person {
public:
	//lifecycle
	Person() = delete;
	Person(const char* name, const char* middleName, const char* lastName, const Date& birthDate, Gender gender);
	Person(const Person& other);
	~Person();

	//getters and setters
	const char* getName() const { return name; }
	const char* getMiddleName() const { return middleName; }
	const char* getLastName() const { return lastName; }
	const Date& getBirthDate() const { return birthDate; }
	Gender getGender() const { return gender; }

	bool setNames(const char* newName, const char* newMiddleName, const char* newLastName);
	bool setLastName(const char* newLastName);

	//methods
	void print();
	bool isSamePerson(const Person& p) const;

private:
	char* name;
	char* middleName;
	char* lastName;
	const Date birthDate;
	const Gender gender;
};