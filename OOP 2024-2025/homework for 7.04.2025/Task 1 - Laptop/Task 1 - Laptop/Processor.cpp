#include "Processor.hpp"
#include <iostream>
#include <exception>

Processor::Processor(): Processor(3, 1, 1) {}

Processor::Processor(double frequency, unsigned int numberOfCores, unsigned cash) {
	if (frequency <= 0) {
		throw std::invalid_argument("Invalid frequency param!");
	}
	if (numberOfCores == 0) {
		throw std::invalid_argument("Invalid number of cores param!");
	}
	if (cash <= 0) {
		throw std::invalid_argument("Invalid cash param!");
	}

	this->frequency = frequency;
	this->numberOfCores = numberOfCores;
	this->cash = cash;
}


double Processor::GetFrequency() const {
	return this->frequency;
}

unsigned int Processor::GetNumberOfCores() const {
	return this->numberOfCores;
}

unsigned int Processor::GetCash() const {
	return this->cash;
}

void Processor::SetFrequency(const double frequency) {
	if (frequency <= 0) {
		std::cout << "Invalid frequency!" << std::endl;
		return;
	}
	else {
		this->frequency = frequency;
	}
}

void Processor::SetNumberOfCores(const unsigned n) {
	if (n == 0) {
		std::cout << "Invalid number of cores!" << std::endl;
		return;
	}
	else {
		this->numberOfCores = n;
	}
}

void Processor::SetCash(const unsigned cash) {
	if (cash <= 0) {
		std::cout << "Invalid cash param!" << std::endl;
		return;
	}
	else {
		this->cash = cash;
	}
}
