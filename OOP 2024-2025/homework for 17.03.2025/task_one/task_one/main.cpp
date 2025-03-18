#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>

#define LINE_LEN 200
#define STR_LEN 30
#define FILE_NAME_LEN 30
#define FACULTY_NUMBER_LEN 11

char commands[4][25] = {
	"1 - Student info",
	"2 - Change email",
	"3 - Save in new file",
	"4 - Exit"
};

int printMenu() {
	for (int i = 0; i < 4; i++) {
		std::cout << commands[i] << std::endl;
	}
	int option = 0;
	std::cout << "Enter command's code: ";
	std::cin >> option;
	while (option < 1 || option > 4) {
		std::cout << "Invalid input!" << std::endl;
		std::cout << "Enter command's code: ";
		std::cin >> option;
	}
	return option;
}

int countFileLines(std::ifstream &f) {
	unsigned  int count = 0;
	char temp[LINE_LEN];
	while (f.getline(temp, LINE_LEN - 1)) {
		count++;
	}
	return count;
}

void openFile(unsigned& lines, char* fileName, bool& exists) {
	std::cout << "Open file:" << std::endl;
	std::cout << ">";
	std::cin >> fileName;

	std::ifstream file(fileName);
	if (!file.is_open()) {
		std::cout << "File doesnt exist or error opening stream!" << std::endl;
		exists = false;
		file.close();
		return;
	}

	lines = countFileLines(file);
	file.close();
}

void loadFile(char* fileName, char**students) {
	std::ifstream file(fileName);
	if (!file.is_open()) {
		std::cout << "Error opening file!" << std::endl;
		file.close();
		return;
	}
	char* line = new (std::nothrow) char[LINE_LEN];
	if (!line) {
		std::cout << "Error alocating memory!" << std::endl;
		return;
	}
	unsigned indexElement = 0;
	while (file.getline(line, LINE_LEN - 1)) {
		char* token = std::strtok(line, ",");
		while (token != nullptr) {
			students[indexElement] = new (std::nothrow) char[strlen(token)];
			if (!students[indexElement]) {
				std::cout << "Error alocating memory!" << std::endl;
				return;
			}
			std::strcpy(students[indexElement], token);
			indexElement++;
			token = std::strtok(nullptr, ",");
		}
	}

	delete[] line;
}

void printDetails(char** students, unsigned lines) {
	char* facultyNumber = new (std::nothrow) char[FACULTY_NUMBER_LEN];
	if (!facultyNumber) {
		std::cout << "Error alocating memory!" << std::endl;
		return;
	}

	std::cout << "Enter faculty number: ";
	std::cin >> facultyNumber;

	bool found = false;
	for (unsigned i = 0; i < lines * 4; i++) {
		if (strcmp(students[i], facultyNumber) == 0) {
			std::cout << students[i - 2] << " ";
			std::cout << students[i - 1] << " ";
			std::cout << students[i] << " ";
			std::cout << students[i + 1] << std::endl;

			found = true;
			break;
		}
	}
	if (!found) {
		std::cout << "There are no students with this faculty number" << std::endl;
	}

	delete[] facultyNumber; //ne raboti i ne znam zasto, 0:53 chasa e rn :(
	//nvm raboti!!! bqh zabravil '\0', ostavqm komentara kato memorial
}

void changeEmail(char** students, unsigned lines) {
	char* facultyNumber = new (std::nothrow) char[FACULTY_NUMBER_LEN];
	if (!facultyNumber) {
		std::cout << "Error alocating memory!" << std::endl;
		return;
	}

	char* newEmail = new (std::nothrow) char[STR_LEN];
	if (!newEmail) {
		std::cout << "Error alocating memory!" << std::endl;
		return;
	}

	std::cout << "Enter faculty number: ";
	std::cin >> facultyNumber;
	std::cin.ignore();
	std::cout << "Enter new email: ";
	std::cin >> newEmail;

	bool found = false;
	for (unsigned i = 0; i < lines * 4; i++) {
		if (strcmp(students[i], facultyNumber) == 0) {
			std::strcpy(students[i + 1], newEmail);
			found = true;
			break;
		}
	}
	if (!found) {
		std::cout << "There are no students with this faculty number" << std::endl;
	}
	delete[] newEmail;
	delete[] facultyNumber;
}

void saveInNewFile(char** students, unsigned lines) {
	char* fileName = new (std::nothrow) char[FILE_NAME_LEN];
	if (!fileName) {
		std::cout << "Error alocating memory!" << std::endl;
		return;
	}

	std::cout << "Enter new file name: ";
	std::cin >> fileName;

	std::ofstream newFile(fileName);
	if (!newFile.is_open()) {
		std::cout << "Error creating new file!" << std::endl;
		return;
	}

	for (int i = 0; i < lines * 4; i++) {
		if ((i + 1) % 4 == 0) {
			newFile << students[i] << "\n";
		}
		else {
			newFile << students[i] << ",";
		}
	}

	newFile.close();
	delete[] fileName;
}

int main() {
	//part 1
	unsigned int lines = 0;
	char* fileName = new(std::nothrow) char[FILE_NAME_LEN];
	bool exists = true;
	if (!fileName) {
		std::cout << "Memory allocation error, try again!" << std::endl;
		return 1;
	}

	openFile(lines, fileName, exists);
	if (!exists) {
		//std::cout << "File doesnt exist or error opening stream!" << std::endl;
		return 1;
	}

	char** students = new (std::nothrow) char* [lines * 4];
	if (!students) {
		std::cout << "Error alocating memory!" << std::endl;
		return 1;
	}
	loadFile(fileName, students);

	int option = printMenu();
	while (true) {
		//part 2 - print details
		if (option == 1) {
			printDetails(students, lines);
		}
		else if (option == 2) {
			changeEmail(students, lines);
		}
		else if (option == 3) {
			saveInNewFile(students, lines);
		}
		else {
			break;
		}

		option = printMenu();
	}
	delete[] students;
	return 0;
}