#define _CRT_SECURE_NO_WARNINGS
#include "Smartphone.hpp"
#include <iostream>

Smartphone::Smartphone(const char* model, const char* brand, double price, const char* os, unsigned int memory) : Phone(model, brand, price)
{
	if (!os || strlen(os) == 0) {
		throw std::invalid_argument("Os can not be a nullptr or empty!");
	}
	if (memory == 0) {
		throw std::invalid_argument("Memory must be a positive number!");
	}

	this->os = new char[strlen(os) + 1];
	strcpy(this->os, os);
	this->memory = memory;
}

Smartphone::Smartphone(const Phone& phone, const char* os, unsigned int memory): Phone(phone)
{
	if (!os || strlen(os) == 0) {
		throw std::invalid_argument("Os can not be a nullptr or empty!");
	}
	if (memory == 0) {
		throw std::invalid_argument("Memory must be a positive number!");
	}

	this->os = new char[strlen(os) + 1];
	strcpy(this->os, os);
	this->memory = memory;
}

Smartphone::Smartphone(const Smartphone& other) : Phone(other)
{
	this->os = new char[strlen(other.os) + 1];
	strcpy(this->os, other.os);
	this->memory = other.memory;
}

Smartphone& Smartphone::operator=(const Smartphone& other)
{
	if (this != &other) {
		Phone::operator=(other);
		char* tempOS = new char[strlen(other.os) + 1];
		strcpy(tempOS, other.os);
		
		delete[] this->os;
		this->os = tempOS;
		this->memory = other.memory;
	}

	return *this;
}

Smartphone::~Smartphone()
{
	delete[] this->os;
}

void Smartphone::setOS(const char* os)
{
	if (!os || strlen(os) == 0) {
		throw std::invalid_argument("OS can not be nullptr or empty!");
	}

	char* tempOS = new char[strlen(os) + 1];
	strcpy(tempOS, os);
	delete[] this->os;
	this->os = tempOS;
}

void Smartphone::setMemory(unsigned int memory)
{
	if (memory == 0) {
		throw std::invalid_argument("Memory must be a positive number!");
	}

	this->memory = memory;
}
