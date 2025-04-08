#pragma once

class Beer {

public:
	//life cycle
	Beer(char const* brand, unsigned ml);

	//getters
	char* getBrand() const { return this->brand; }
	unsigned getMl() const { return this->ml; }

	//methods
	void addBeer(Beer bonusBeer); //why would you mix beers :(
	void fillBeer(unsigned ml);   //now that's a great option :)
	//bool checkBeer(char* brand); //I am not sure what this is supposed to do, why would you have two brands in one bottle

private:
	char* brand;
	unsigned ml;
};