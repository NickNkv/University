#pragma once
#include "Processor.hpp"

class Laptop {
public:

private:
	char* brand;
	char* model;
	double price;
	double screenLen; //inches
	Processor processor;
	unsigned ram;
	unsigned battery;
};