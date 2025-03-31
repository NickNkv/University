#include <iostream>
#include "Complex.hpp"

void Complex::print()
{
	std::cout << this->real << " + " << this->imag << "i" << std::endl;
}