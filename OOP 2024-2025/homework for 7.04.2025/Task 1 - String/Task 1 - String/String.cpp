#define _CRT_SECURE_NO_WARNINGS
#include "String.hpp"
#include <iostream>
#include <cstring>

String::String() {
	this->capacity = 16;
	this->string = new (std::nothrow) char[capacity + 1];
	if (this->string) this->string[0] = '\0';
}

String::String(size_t capacity) {
	this->capacity = capacity;
	this->string = new (std::nothrow) char[this->capacity + 1];
	if (this->string) this->string[0] = '\0';
}

String::String(char const* string) {
	this->capacity = strlen(string);
	this->string = new (std::nothrow) char[capacity + 1];
	if (this->string) std::strcpy(this->string, string);
}

void String::Copy(const char* str) {
	char* temp = new (std::nothrow) char[strlen(str) + 1];
	if (!temp) return;
	strcpy(temp, str);
	delete[] this->string;

	this->capacity = strlen(str);
	this->string = temp;
	temp = nullptr;
}

void String::Append(const char* str) {
	char* oldStr = new (std::nothrow) char[this->capacity + 1];
	if (!oldStr) return;
	strcpy(oldStr, this->string);

	delete[] this->string;

	//preparing this->strig for the new value
	this->capacity += strlen(str);
	this->string = new (std::nothrow) char[this->capacity + 1];
	if (!string) return;
	strcpy(this->string, oldStr);

	size_t oldStrLen = strlen(oldStr) + 1;
	for (int i = oldStrLen - 1; i < capacity; i++) {
		this->string[i] = str[i - oldStrLen + 1];
		//std::cout << str[i - oldStrLen + 1];
	}
	this->string[capacity] = '\0';
}

const char* String::Combine(const char* str) {
	String temp(this->string);
	temp.Append(str);

	return temp.c_str();
}

const char* String::c_str() {
	return this->string;
}

size_t String::Length() {
	return this->capacity;
}

void String::Clear() {
	delete[] this->string;
	this->string = nullptr;
	this->capacity = 0;
}

bool String::Empty() {
	return capacity == 0 ? true : false;
}

char String::At(size_t position) {
	if (position < capacity) {
		return this->string[position];
	}
	std::cout << "Invalid index!" << std::endl;
	std::cout << "Returning 'x' as a default value" << std::endl;
	return 'x';
}



