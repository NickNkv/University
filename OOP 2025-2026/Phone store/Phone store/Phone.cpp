#define _CRT_SECURE_NO_WARNINGS
#include "Phone.hpp"
#include <iostream>
#include <exception>

Phone::Phone(const char* model, const char* brand, double price)
{
	if (!model || strlen(model) == 0) {
		throw std::invalid_argument("Model can not be a nullptr or empty!");
	}
	if (!brand || strlen(brand) == 0) {
		throw std::invalid_argument("Brand can not be a nullptr or empty!");
	}
	if (price <= 0) {
		throw std::invalid_argument("Price must be a positive number!");
	}

	this->model = new char[strlen(model) + 1];
	this->brand = new (std::nothrow) char[strlen(brand) + 1];
	if (!this->brand) {
		delete[] this->model;
		throw std::bad_alloc();
	}

	strcpy(this->model, model);
	strcpy(this->brand, brand);
	this->price = price;
}

Phone::Phone(const Phone& other)
{
	this->model = new char[strlen(other.model) + 1];
	this->brand = new (std::nothrow) char[strlen(other.brand) + 1];
	if (!brand) {
		delete[] this->model;
		throw std::bad_alloc();
	}

	strcpy(this->model, other.model);
	strcpy(this->brand, other.brand);
	this->price = other.price;
}

Phone& Phone::operator=(const Phone& other)
{
	if (this != &other) {
		char* tempModel = new char[strlen(other.model) + 1];
		char* tempBrand = new (std::nothrow) char[strlen(other.brand) + 1];
		if (!tempBrand) {
			delete[] tempModel;
			throw std::bad_alloc();
		}

		strcpy(tempModel, other.model);
		strcpy(tempBrand, other.brand);

		delete[] this->model;
		delete[] this->brand;
		this->model = tempModel;
		this->brand = tempBrand;
		this->price = other.price;
	}

	return *this;
}

Phone::~Phone()
{
	delete[] this->model;
	delete[] this->brand;
}

void Phone::setModel(const char* model)
{
	if (!model || strlen(model) == 0) {
		throw std::invalid_argument("Model can not be a nullptr or empty!");
	}

	char* tempModel = new char[strlen(model) + 1];
	strcpy(tempModel, model);

	delete[] this->model;
	this->model = tempModel;
}

void Phone::setBrand(const char* brand)
{
	if (!brand || strlen(brand) == 0) {
		throw std::invalid_argument("Brand can not be a nullptr or empty!");
	}

	char* tempBrand = new char[strlen(brand) + 1];
	strcpy(tempBrand, brand);

	delete[] this->brand;
	this->brand = tempBrand;
}

void Phone::setPrice(double price)
{
	if (price <= 0) {
		throw std::invalid_argument("Price must be a positive number!");
	}

	this->price = price;
}

void Phone::print()
{
	std::cout << "Model: " << this->model << "  Brand: " << this->brand << "   Price: " << this->price << "\n";
}
