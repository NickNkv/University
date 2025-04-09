#include "Interval.hpp"
#include <iostream>

//life cycle
Interval::Interval() {
	this->a = 0;
	this->b = 0;
}

Interval::Interval(int a, int b) {
	if (a <= b) {
		this->a = a;
		this->b = b;
	}
	else {
		std::cout << "Invalid interval! Creating default: [0,0]" << std::endl;
		this->a = 0;
		this->b = 0;
	}
}

//getters
int Interval::GetA() const {
	return this->a;
}

int Interval::GetB() const {
	return this->b;
}

//setters
void Interval::SetA(int a) {
	if (a <= this->b) {
		this->a = a;
	}
	else {
		std::cout << "Setting 'a' unsuccessful!\nCondition: a <= b" << std::endl;
	}
}

void Interval::SetB(int b) {
	if (b >= this->a) {
		this->b = b;
	}
	else {
		std::cout << "Setting 'b' unsuccessful!\nCondition: a <= b" << std::endl;
	}
}

void Interval::SetBothAB(int a, int b) {
	if (a <= b) {
		this->a = a;
		this->b = b;
	}
	else {
		std::cout << "Setting 'a' and 'b' unsuccessful!\nCondition: a <= b" << std::endl; 
	}
}

//methods
int Interval::Length() {
	return this->b - this->a;
}

bool Interval::IsInInterval(int number) {
	if (number >= this->a && number <= this->b) {
		return true;
	}
	else {
		return false;
	}
}

