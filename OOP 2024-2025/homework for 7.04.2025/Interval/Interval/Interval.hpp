#pragma once

class Interval {
public:
	//life cycle
	Interval();
	Interval(int a, int b);

	//getters
	int GetA() const;
	int GetB() const;

	//setters
	void SetA(int a);
	void SetB(int b);
	void SetBothAB(int a, int b);

	//methods
	int Length();
	bool IsInInterval(int number);
	unsigned NumberOfPrimes();
	unsigned NumberOfPalindromes();
	unsigned NumberOfUniqueDigits();
	bool IsPowerTwo();
	Interval Intersect(const Interval& interval);
	bool IsSubInterval(const Interval& interval);


private:
	int a;
	int b;
};