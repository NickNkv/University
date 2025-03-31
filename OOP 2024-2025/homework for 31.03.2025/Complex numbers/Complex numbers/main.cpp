#include <iostream>
#include "Complex.hpp"

//sledvastite funkcii po dobre da sa static kum klasa Complex ama kato ne sme go uchili :d
Complex sum(const Complex& a, const Complex& b) {
	Complex result;
	result.setReal(a.getReal() + b.getReal());
	result.setImag(a.getImag() + b.getImag());

	return result;
}

Complex substract(const Complex& a, const Complex& b) {
	Complex result;
	result.setReal(a.getReal() - b.getReal());
	result.setImag(a.getImag() - b.getImag());
	return result;
}

Complex multiply(const Complex& a, const Complex& b) {
	Complex result;
	double realPart = a.getReal() * b.getReal() - a.getImag() * b.getImag();
	double imaginaryPart = a.getReal() * b.getImag() - a.getImag() * b.getReal();
	result.setReal(realPart);
	result.setImag(imaginaryPart);
	return result;
}

int main() {
	std::cout << "Numbers" << std::endl;
	Complex k;
	k.setReal(10);
	k.setImag(11);
	k.print();

	Complex l;
	l.setReal(5);
	l.setImag(20);
	l.print();

	std::cout << "\nSum\n";
	Complex p = sum(k, l);
	p.print();

	std::cout << "\nSubstract\n";
	p = substract(k, l);
	p.print();

	std::cout << "\nMultiply\n";
	p = multiply(k, l);
	p.print();

	return 0;
}