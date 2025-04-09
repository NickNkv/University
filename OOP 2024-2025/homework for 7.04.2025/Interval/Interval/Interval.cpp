#include "Interval.hpp"
#include <iostream>

//life cycle
Interval::Interval() {
	this->a = 0;
	this->b = 0;
}

Interval::Interval(int a, int b) {
	if (a <= b) {
		this->a = a;
		this->b = b;
	}
	else {
		std::cout << "Invalid interval! Creating default: [0,0]" << std::endl;
		this->a = 0;
		this->b = 0;
	}
}

//getters
int Interval::GetA() const {
	return this->a;
}

int Interval::GetB() const {
	return this->b;
}

//setters
void Interval::SetA(int a) {
	if (a <= this->b) {
		this->a = a;
	}
	else {
		std::cout << "Setting 'a' unsuccessful!\nCondition: a <= b" << std::endl;
	}
}

void Interval::SetB(int b) {
	if (b >= this->a) {
		this->b = b;
	}
	else {
		std::cout << "Setting 'b' unsuccessful!\nCondition: a <= b" << std::endl;
	}
}

void Interval::SetBothAB(int a, int b) {
	if (a <= b) {
		this->a = a;
		this->b = b;
	}
	else {
		std::cout << "Setting 'a' and 'b' unsuccessful!\nCondition: a <= b" << std::endl; 
	}
}

//methods
int Interval::Length() {
	return this->b - this->a;
}

bool Interval::IsInInterval(int number) {
	if (number >= this->a && number <= this->b) {
		return true;
	}
	else {
		return false;
	}
}

bool isPrime(int n) {
	if (n <= 1) return false;
	if (n <= 3) return true;

	if (n % 2 == 0 || n % 3 == 0) return false;

	for (int i = 5; i * i <= n; i += 6) {
		if (n % i == 0 || n % (i + 2) == 0) return false;
	}
	return true;
}

unsigned Interval::NumberOfPrimes() {
	unsigned count = 0;
	for (int i = this->a; i <= this->b; i++) {
		if (isPrime(i)) {
			count++;
		}
	}
	return count;
}

bool isPalindrome(int n) {
	if (n < 10) return true;

	int original = n;
	int reversed = 0;

	while (n != 0) {
		int digit = n % 10;
		if (reversed > (INT_MAX) / 10) {
			return false;
		}
		reversed = reversed * 10 + digit;
		n /= 10;
	}

	return original == reversed;
}

unsigned Interval::NumberOfPalindromes() {
	unsigned count = 0;
	for (int i = this->a; i <= this->b; i++) {
		if (isPalindrome(i)) {
			count++;
		}
	}

	return count;
}

bool hasUniqueDigits(int n) {
	bool seen[10] = { false };
	n = std::abs(n);

	while (n > 0) {
		int digit = n % 10;
		if (seen[digit]) {
			return false;
		}
		seen[digit] = true;
		n /= 10;
	}
	return true;
}

unsigned Interval::NumberOfUniqueDigits() {
	unsigned count = 0;
	for (int i = this->a; i <= this->b; i++) {
		if (hasUniqueDigits(i)) {
			count++;
		}
	}

	return count;
}

bool isPowTwo(int n) {
	if (n <= 0) return false;
	return (n & (n - 1)) == 0;
}

bool Interval::IsPowerTwo() {
	return isPowTwo(this->a) && isPowTwo(this->b);
}

Interval Interval::Intersect(const Interval& interval)
{
	if (this->a > interval.b || this->b < interval.a) {
		return Interval();
	}

	if (this->a >= interval.a) {
		if (this->b <= interval.b) {
			return Interval(this->a, this->b);
		}
		else {
			return Interval(this->a, interval.b);
		}
	}
	else {
		if (this->b <= interval.b) {
			return Interval(interval.a, this->b);
		}
		else {
			return Interval(interval.a, interval.b);
		}
	}
}

bool Interval::IsSuperInterval(const Interval& interval) {
	if (this->a <= interval.a && this->b >= interval.b) {
		return true;
	}
	else {
		return false;
	}
}

void Interval::Print() {
	std::cout << "[" << this->a << ", " << this->b << "]" << std::endl;
}

