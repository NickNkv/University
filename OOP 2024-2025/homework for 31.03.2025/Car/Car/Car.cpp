#include "Car.h"
#include <iostream>

void Car::upgrade()
{
	const int upgradeValue = 15;
	const int maxValue = 150;

	if (this->power + upgradeValue <= maxValue) {
		this->power += upgradeValue;
		std::cout << "Upgrading...\nCurrent power: " << this->power << std::endl;
	}
	else {
		std::cout << "Maximum upgrade value reached!" << std::endl;
	}
}

void Car::fill()
{
	this->gas = 100;
	std::cout << "Gas filled to 100%" << std::endl;
}

void Car::drive(unsigned int km)
{
	unsigned int gasNeeded = km * (this->power / 15);
	if (gasNeeded > this->gas) {
		std::cout << "Insufficient gas!\n";
		std::cout << "Current gas: " << this->gas << "\n";
		std::cout << "Gas needed: " << gasNeeded << std::endl;
	}
	else {
		this->gas -= gasNeeded;
		std::cout << "Driving...\n";
		std::cout << "Remaining gas: " << this->gas << std::endl;
	}
}
