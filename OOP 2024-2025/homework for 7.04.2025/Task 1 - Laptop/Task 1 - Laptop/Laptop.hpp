#pragma once
#include "Processor.hpp"

class Laptop {
public:
	Laptop();
	Laptop(const char* brand, const char* model, double price, double screenLen, Processor processor, unsigned ram, unsigned battery);

private:
	char* brand;
	char* model;
	double price;
	double screenLen; //inches
	Processor processor;
	unsigned ram;
	unsigned battery;
};