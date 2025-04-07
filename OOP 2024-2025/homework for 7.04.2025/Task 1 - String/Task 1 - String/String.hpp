#pragma once

class String {
public:
	//life cycle
	String();
	String(size_t capacity);
	String(char const* string);

	//methods
	void Copy(const char* str); //kakvo tochno da kopira? ne sum siguren v uslovieto
	void Append(const char* str);
	const char* c_str();


private:
	char* string;
	size_t capacity;
};