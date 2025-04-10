#pragma once

class Processor {
public:
	Processor();
	Processor(double frequency, unsigned int numberOfCores, unsigned int cash);

	double GetFrequency() const;
	unsigned int GetNumberOfCores() const;
	unsigned int GetCash() const;

	void SetFrequency(const double frequency);
	void SetNumberOfCores(const unsigned n);
	void SetCash(const unsigned cash);

private:
	double frequency; //in GHz
	unsigned int numberOfCores;
	unsigned int cash;
};