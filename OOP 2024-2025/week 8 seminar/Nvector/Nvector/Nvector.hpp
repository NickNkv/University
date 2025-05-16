#pragma once

class Nvector
{
public:
	Nvector(); //creates the null vector
	Nvector(int size, double* values);
	Nvector(Nvector const &other);
	~Nvector();
	Nvector& operator=(Nvector const& other);

	Nvector& operator+=(const Nvector&);
	Nvector& operator-=(const Nvector&);

	double& operator[] (size_t index);
	const double& operator[] (size_t index) const;

	const double getSize() const { return size; }
	bool isParallelTo(const Nvector& other);
	void print();

private:
	unsigned size;
	double* data;
};

//aritmetika s 2 vectora
const Nvector operator+(const Nvector& lhs, const Nvector& rhs);
const Nvector operator-(const Nvector& lhs, const Nvector& rhs);

//aritmetika sus skalar
//const Rational operator + (int, const Rational&);
const Nvector operator*(double scalar, const Nvector& rhs);
const Nvector operator*(const Nvector& lhs, double scalar);