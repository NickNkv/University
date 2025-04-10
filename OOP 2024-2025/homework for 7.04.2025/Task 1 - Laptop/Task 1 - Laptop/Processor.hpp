#pragma once

class Processor {
public:
	Processor();
	Processor(double frequency, unsigned int numberOfCores, double cash);

	double GetFrequency() const;
	unsigned int GetNumberOfCores() const;
	double GetCash() const;

	void SetFrequency(const double frequency);
	void SetNumberOfCores(const unsigned n);
	void SetCash(double cash);

private:
	double frequency; //in GHz
	unsigned int numberOfCores;
	double cash;
};