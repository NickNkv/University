#define _CRT_SECURE_NO_WARNINGS
#include "Person.hpp"
#include <iostream>

//for the purpose of the test task we leave the constructors poorly written

Person::Person() {
	this->name = new char[5];
	strcpy(name, "none\0");
	strcpy(this->id, "0123456789\0");
	this->age = 100;
}

Person::Person(const char* name, const char* id, int age) {
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	strcpy(this->id, id);
	this->age = age;
}

void Person::setName(const char* name) {
	delete[] this->name;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

void Person::setId(const char id[10]) {
	strcpy(this->id, id);
}

void Person::setAge(const int age) {
	this->age = age;
}


