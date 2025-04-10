#define _CRT_SECURE_NO_WARNINGS
#include "Laptop.hpp"
#include <iostream>

Laptop::Laptop() {
	this->brand = new char[10];
	this->model = new (std::nothrow) char[10];
	if (!model) {
		delete[] brand;
		throw std::bad_alloc();
	}

	this->price = 1000;
	this->screenLen = 10;
	Processor p;
	this->processor = p;
	this->ram = 8;
	this->battery = 10000;
}

Laptop::Laptop(const char* brand, const char* model, double price, double screenLen, Processor processor, unsigned ram, unsigned battery) {
	char* tempBrand = new char[strlen(brand) + 1];
	char* tempModel = new (std::nothrow) char[strlen(model) + 1];
	if (!tempModel) {
		delete[] brand;
		throw std::bad_alloc();
	}
	strcpy(tempBrand, brand);
	strcpy(tempModel, model);

	if (price < 0) {
		throw std::invalid_argument("Invalid price param");
	}
	if (screenLen <= 0) {
		throw std::invalid_argument("Invalid screen length param");
	}
}
