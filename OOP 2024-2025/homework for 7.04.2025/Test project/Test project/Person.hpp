#pragma once

class Person {
public:
	Person();
	Person(const char* name, const char* id, int age);

	char* getName() const { return name; }
	const char* getId() const { return id; }
	int getAge() const { return age; }

	void setName(const char* name);
	void setId(const char id[11]);
	void setAge(const int age);
	int getblabla() const;

private:
	char* name;
	char id[11];
	int age;
	int blabla;
};