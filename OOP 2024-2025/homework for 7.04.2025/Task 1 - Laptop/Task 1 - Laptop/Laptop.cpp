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
		delete[] tempBrand;
		throw std::bad_alloc();
	}
	if (price < 0) {
		delete[] tempBrand;
		delete[] tempModel;
		throw std::invalid_argument("Invalid price param");
	}
	if (screenLen <= 0) {
		delete[] tempBrand;
		delete[] tempModel;
		throw std::invalid_argument("Invalid screen length param");
	}
	if (ram == 0) {
		delete[] tempBrand;
		delete[] tempModel;
		throw std::invalid_argument("Invalid ram param");
	}
	if (battery == 0) {
		delete[] tempBrand;
		delete[] tempModel;
		throw std::invalid_argument("Invalid battery param");
	}
	
	strcpy(tempBrand, brand);
	strcpy(tempModel, model);

	this->price = price;
	this->screenLen = screenLen;
	this->processor = processor;
	this->ram = ram;
	this->battery = battery;
}

Laptop::Laptop(const Laptop& o) {
	char* tempBrand = new char[strlen(o.brand) + 1];
	char* tempModel = new (std::nothrow) char[strlen(o.model) + 1];
	if (!tempModel) {
		std::cout << "Bad alloc! Try again!" << std::endl;
		delete[] tempBrand;
		throw std::bad_alloc();
	}

	this->brand = tempBrand;
	this->model = tempModel;
	this->price = o.price;
	this->screenLen = o.screenLen;
	this->processor = o.processor;
	this->ram = o.ram;
	this->battery = o.battery;
}
