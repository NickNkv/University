#pragma once

class String {
public:
	//life cycle
	String();
	String(size_t capacity);
	String(char const* string);

	//methods
	void Copy(const char* str);
	void Append(const char* str);
	const char* Combine(const char* str);
	const char* c_str();
	size_t Length();
	void Clear();
	bool Empty();
	char At(size_t position);

private:
	char* string;
	size_t capacity;
};