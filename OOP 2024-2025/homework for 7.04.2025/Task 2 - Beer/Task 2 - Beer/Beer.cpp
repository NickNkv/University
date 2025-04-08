#define _CRT_SECURE_NO_WARNINGS
#include "Beer.hpp"
#include <iostream>
#include <cstring>

Beer::Beer(char const* brand, unsigned ml) {
	if (strlen(brand) < 128) {
		std::cout << "Exceeded max brand name length (127 characters)!" << std::endl;
		this->brand = nullptr;
		this->ml = 0;
	}
	else {
		this->brand = new (std::nothrow) char[strlen(brand) + 1];
		if (!this->brand) {
			this->brand = nullptr;
		}
		else {
			strcpy(this->brand, brand);
		}
		this->ml = ml;
	}
	
}

void Beer::addBeer(Beer bonusBeer) {
	this->ml += bonusBeer.getMl(); //? nz
}

void Beer::fillBeer(unsigned ml) {
	this->ml += ml;
}