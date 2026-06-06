#pragma once

class Phone {
public:
	Phone() = delete; //a phone with properties (nullptr, nullptr, 0) is not needed
	Phone(const char* model, const char* brand, double price);
	Phone(const Phone& other);
	Phone& operator = (const Phone& other);
	virtual ~Phone();
	virtual Phone* clone() const { return new Phone(*this); }

	const char* getModel() const { return model; }
	void setModel(const char* model);

	const char* getBrand() const { return brand; }
	void setBrand(const char* brand);

	virtual double getPrice() const { return price; }
	void setPrice(double price);

	virtual void print();

private:
	char* model;
	char* brand;
	double price;
};