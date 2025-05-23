#pragma once
#include "Processor.hpp"

class Laptop {
public:
	Laptop();
	Laptop(const char* brand, const char* model, double price, double screenLen, Processor processor, unsigned ram, unsigned battery);
	Laptop(const Laptop& o);
	Laptop& operator=(const Laptop& laptop);

private:
	char* brand;
	char* model;
	double price;
	double screenLen; //inches
	Processor processor;
	unsigned ram;
	unsigned battery;
};