#include "Nvector.hpp"
#include <iostream>
#include <exception>

Nvector::Nvector() {
	this->data = new (std::nothrow) double[1];
	if (!this->data) {
		throw std::bad_alloc();
	}
	this->size = 1;
	data[0] = 0;
}

Nvector::Nvector(int size, double* values) {
	if (size <= 0) {
		std::cout << "Vector size must be apositive number" << std::endl;
		throw std::invalid_argument("Invalid vector size argument!");
	}

	this->data = new (std::nothrow) double[size];
	if (!this->data) {
		throw std::bad_alloc();
	}

	this->size = (unsigned)size;
	for (int i = 0; i < size; i++) {
		this->data[i] = values[i];
	}
}

Nvector::Nvector(Nvector const& other) {
	this->data = new (std::nothrow) double[other.size];
	if (!this->data) {
		throw std::bad_alloc();
	}
	for (int i = 0; i < other.size; i++) {
		this->data[i] = other.data[i];
	}
	this->size = other.size;
}

Nvector::~Nvector() {
	delete[] this->data;
}

Nvector& Nvector::operator=(Nvector const& other) {
	if (this == &other) {
		return *this;
	}

	double* tempData = new (std::nothrow) double[other.size];
	if (!tempData) {
		throw std::bad_alloc();
	}

	for (int i = 0; i < other.size; i++) {
		tempData[i] = other.data[i];
	}

	delete[] this->data;
	this->data = tempData;
	tempData = nullptr;
	this->size = other.size;

	return *this;
}

//operator overload
Nvector& Nvector::operator+=(const Nvector& rhs) {
	if (this->size < rhs.size) {
		double* temp = new double[rhs.size];
		for (int i = 0; i < rhs.size; i++) {
			if (i >= this->size) {
				temp[i] = rhs.data[i];
			}
			else {
				temp[i] = this->data[i] + rhs.data[i];
			}
		}

		delete[] this->data;
		this->data = temp;
		temp = nullptr;
		this->size = rhs.size;
	}
	else {
		for (int i = 0; i < rhs.size; i++) {
			this->data[i] += rhs.data[i];
		}
	}

	return *this;
}

Nvector& Nvector::operator-=(const Nvector& rhs) {
	if (this->size < rhs.size) {
		double* temp = new double[rhs.size];
		for (int i = 0; i < rhs.size; i++) {
			if (i >= this->size) {
				temp[i] = 0 - rhs.data[i];
			}
			else {
				temp[i] = this->data[i] - rhs.data[i];
			}
		}

		delete[] this->data;
		this->data = temp;
		temp = nullptr;
		this->size = rhs.size;
	}
	else {
		for (int i = 0; i < rhs.size; i++) {
			this->data[i] -= rhs.data[i];
		}
	}

	return *this;
}

double& Nvector::operator[](size_t index)
{
	return this->data[index];
}

const double& Nvector::operator[](size_t index) const
{
	return this->data[index];
}


bool Nvector::isParallelTo(const Nvector& other) {
	return false;
}

void Nvector::print() {
	std::cout << "Size: " << this->size << std::endl;
	for (int i = 0; i < this->size; i++) {
		std::cout << this->data[i] << " ";
	}
}

const Nvector operator + (const Nvector& lhs, const Nvector& rhs)
{
	unsigned rhsSize = rhs.getSize();
	unsigned lhsSize = lhs.getSize();
	Nvector temp;
	if (lhsSize > rhsSize) {
		temp = lhs;
		for (int i = 0; i < rhsSize; i++) {
			temp[i] += rhs[i];
		}
	}
	else {
		temp = rhs;
		for (int i = 0; i < lhs.getSize(); i++) {
			temp[i] += lhs[i];
		}
	}
	Nvector result = lhs;
	result += rhs;
	return result;
}

const Nvector operator-(const Nvector& lhs, const Nvector& rhs)
{
	Nvector result = lhs;
	result -= rhs;
	return result;
}

//aritmetikata sus skalar
const Nvector operator*(double scalar, const Nvector& rhs) {
	Nvector result = rhs;
	for (int i = 0; result.getSize(); i++) {
		result[i] *= scalar;
	}

	return result;
}

const Nvector operator*(const Nvector& lhs, double scalar) {
	Nvector result = lhs;
	for (int i = 0; i < result.getSize(); i++) {
		result[i] = result[i] * scalar;
	}

	return result;
}

