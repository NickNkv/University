#include <iostream>
#include "String.hpp"

int main() {
	String str1("Nick ");
	String str2("Neykov");

	str1.Append(str2.c_str());

	std::cout << str1.c_str() << std::endl;
	return 0;
}