#pragma once

class Person {
public:
	Person();
	Person(const char* name, const char* id, int age);

	char* getName() 

private:
	char* name;
	char id[11];
	int age;
};