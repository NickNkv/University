#include "utils.h"

const char* utils::getGender(Gender gender)
{
	if (gender == Gender::Male) {
		return "Male";
	}
	else if (gender == Gender::Female) {
		return "Female";
	}
	else {
		return "undefined";
	}
}
