#include <iostream>
#include <fstream>
#include "Person.hpp";


bool write(std::ofstream& out, const Person& p) {
	if (!out) {
		return false;
	}

	size_t len = strlen(p.getName());
	out.write((const char*)&len, sizeof(len));
	out.write(p.getName(), len * sizeof(char));

	const char* id = p.getId();
	out.write(id, 10 * sizeof(char));
	int age = p.getAge();
	out.write((const char*)&age, sizeof(int));
	
	return out.good();
}

bool read(std::istream& in, Person& p) {
	if (!in) {
		return false;
	}

	size_t len;
	in.read((char*)&len, sizeof(len));
	if (!in || in.gcount() != sizeof(len)) {
		return false;
	}

	char* name = new (std::nothrow) char[len + 1];
	if (!name) {
		return false;
	}

	in.read(name, len * sizeof(char));
	if (!in || in.gcount() != len * sizeof(char)) {
		delete[] name;
		return false;
	}
	name[len] = '\0';

	char id[11];
	in.read(id, 10 * sizeof(char));
	if (!in || in.gcount() != 10 * sizeof(char)) {
		delete[] name;
		return false;
	}
	id[10] = '\0';

	int age;
	in.read((char*)&age, sizeof(int));
	if (!in || in.gcount() != sizeof(int)) {
		delete[] name;
		return false;
	}

	p.setName(name);
	p.setId(id);
	p.setAge(age);

	return in.good();
}

int main() {
	std::ofstream f("output.dat", std::ios::binary);
	Person per("Nick", "1234567899", 19);

	write(f, per);
	f.close();

	Person newP;
	std::ifstream i("output.dat", std::ios::binary);
	read(i, newP);

	std::cout << newP.getName() << "\n" << newP.getId() << "\n" << newP.getAge();
	i.close();
	return 0;
}