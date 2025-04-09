#include <iostream>
#include "Interval.hpp"

int main() {
	Interval j(5, 8);
	Interval i(5, 8);
	Interval p = i.Intersect(j);
	p.Print();

	Interval t1(3, 14); // [3, 10]
	Interval t2(4, 10); // [4, 14]

	std::cout << t1.IsSuperInterval(t2) << std::endl;

	return 0;
}