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
	this->name = new char[5];
	strcpy(this->name, name);
	strcpy(this->id, id);
	this->age = age;
}
