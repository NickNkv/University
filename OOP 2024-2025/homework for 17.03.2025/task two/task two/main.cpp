#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>

#define MAX_DATA 1024

int printMenu() {
	std::cout << "1 - View file\n2 - Change byte\n3 - Remove last byte\n";
	std::cout << "4 - Add byte\n5 - Save changes\n6 - Save as (in new file)\n7 - Exit" << std::endl;
	
	int option = 0;
	std::cout << "Enter command's code: ";
	std::cin >> option;
	while (option < 1 || option > 7) {
		std::cout << "Invalid input!" << std::endl;
		std::cout << "Enter command's code: ";
		std::cin >> option;
	}
	return option;
}

void loadFile(char* fileName, bool& isFileOpened, unsigned& fileSize, unsigned char* data) {
	std::cout << "Open file:" << std::endl << ">";
	std::cin >> fileName;

	std::ifstream file(fileName, std::ios::binary);
	if (!file.is_open()) {
		std::cout << "Error opening file!" << std::endl;
		isFileOpened = false;
		return;
	}
	isFileOpened = true;

	file.seekg(0, std::ios::end);
	fileSize = file.tellg();
	if (fileSize > MAX_DATA) {
		fileSize = MAX_DATA;
	}

	file.seekg(0, std::ios::beg);

	std::cout << "file opened " << fileSize << " bytes" << std::endl;
	file.read((char*)data, fileSize);

	file.close();
}

void viewFile(unsigned fileSize, unsigned char* data) {
	for (int i = 0; i < fileSize; i++) {
		unsigned char byte = data[i];
		//std::cout << byte + '0' << std::endl;
		char hex[10];
		sprintf(hex, "%02X", byte);
		std::cout << hex << " ";
		if ((i + 1) % 16 == 0) {
			std::cout << std::endl;
		}
	}

	std::cout << std::endl;

	for (int i = 0; i < fileSize; i++) {
		unsigned char byte = data[i];
		//std::cout << byte + '0' << std::endl;
		std::cout << byte;
		if ((i + 1) % 16 == 0) {
			std::cout << std::endl;
		}
	}
	std::cout << std::endl;
}

void changeByte(unsigned int fileSize, unsigned char* data) {
	int index = 0;
	char hex[10];
	std::cout << "Enter index: ";
	std::cin >> index;
	std::cin.clear();
	std::cout << "Enter new byte in hex: ";
	std::cin >> hex;
	if (index >= 0 && index < fileSize) {
		data[index] = (unsigned char) strtol(hex, nullptr, 16);
	}
}

void removeLastByte(unsigned& fileSize) {
	if (fileSize > 0) {
		fileSize--;
	}
}

void addByte(unsigned& fileSize, unsigned char* data) {
	char hex[10];
	std::cin.clear();
	std::cout << "Enter new byte in hex: ";
	std::cin >> hex;

	if (fileSize < MAX_DATA) {
		data[fileSize] = (unsigned char)strtol(hex, nullptr, 16);
		fileSize += 1;
	}
}

void saveFile(char* fileName, unsigned int fileSize, unsigned char* data) {
	std::ofstream file(fileName, std::ios::binary);
	if (!file.is_open()) {
		std::cout << "Error saving file!" << std::endl;
		return;
	}
	file.write((const char*)&data, fileSize);
	file.close();
}

int main() {
	int x = 25409;
	std::ofstream file("myData.dat", std::ios::binary);
	file.write((const char*)&x, sizeof(x));
	file.close();

	char* fileName = new (std::nothrow) char[201];
	if (!fileName) {
		std::cout << "Error alocating memory!" << std::endl;
		return 1;
	}
	bool isFileOpened = false;
	unsigned int fileSize = 0;
	unsigned char* data = new (std::nothrow) unsigned char[MAX_DATA];
	if (!fileName) {
		std::cout << "Error alocating memory!" << std::endl;
		return 1;
	}

	loadFile(fileName, isFileOpened, fileSize, data);

	if (!isFileOpened) {
		return 1;
	}

	int choice = 0;
	while (true) {
		choice = printMenu();
		if (choice == 1) {
			viewFile(fileSize, data);
		}
		else if (choice == 2) {
			changeByte(fileSize, data);
		}
		else if (choice == 3) {
			removeLastByte(fileSize);
		}
		else if (choice == 4) {
			addByte(fileSize, data);
		}
		else if (choice == 5) {
			saveFile(fileName, fileSize, data);
		}
		else if (choice == 6) {
			char* newFileName = new (std::nothrow) char[256];
			std::cout << "Enter new file name: ";
			std::cin >> newFileName;
			saveFile(newFileName, fileSize, data);
			delete[] newFileName;
		}
		else {
			break;
		}
	}

	delete[] fileName;
	delete[] data;
	return 0;
}