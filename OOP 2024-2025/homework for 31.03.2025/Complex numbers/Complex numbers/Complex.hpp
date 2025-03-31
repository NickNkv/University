#pragma once

class Complex 
{
public:
	//getters
	double getReal() const { return real; }
	double getImag() const { return imag; }

	//setters
	void setReal(double a) { real = a; }
	void setImag(double b) { imag = b; }

	void print();

private:
	double real = 0; //real part
	double imag = 0; //imaginary part
};