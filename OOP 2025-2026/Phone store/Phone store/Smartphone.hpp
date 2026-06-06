#pragma once

#include "Phone.hpp"

class Smartphone : public Phone {
public:
	Smartphone() = delete;
	Smartphone(const char* model, const char* brand, double price, const char* os, unsigned int memory);
	Smartphone(const Phone& phone, const char* os, unsigned int memory);
	Smartphone(const Smartphone& other);
	Smartphone& operator = (const Smartphone& other);
	~Smartphone() override;

	const char* getOS() const { return os; }
	void setOS(const char* os);

	unsigned int getMemory() const { return memory; }
	void setMemory(unsigned int memory);

	double getPrice() const override { return Phone::getPrice() + memory; }

private:
	char* os;
	unsigned int memory;
};