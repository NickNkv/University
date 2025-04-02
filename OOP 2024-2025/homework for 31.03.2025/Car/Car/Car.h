#pragma once

class Car
{
public:
	//getters
	unsigned getPower() const { return power; }
	double getGas() const { return gas; }
	unsigned getDistance() const { return distance; }

	//methods
	void upgrade();
	void fill();
	void drive(unsigned int km);

private:
	unsigned int power = 90; //max 150
	double gas = 0;
	unsigned int distance = 0;
};