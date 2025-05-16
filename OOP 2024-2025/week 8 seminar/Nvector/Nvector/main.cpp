#include <iostream>
#include "Nvector.hpp"

int main() {
	double elements[] = { 1, 5, 2 };
	double elements2[] = {2, 5, 2, 7, 8};
	Nvector a(3, elements);
	Nvector b(5, elements2);
	Nvector c;

	a = a * 5;
	a.print();

	return 0;
}