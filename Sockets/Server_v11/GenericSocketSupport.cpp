#include <string>
#include <vector>

std::string BufferToString(char CharBuffer[], int buffer_size) {
	int i = 0;
	std::string s;
	while (i < buffer_size) { s += CharBuffer[i++]; }
	return s;
}

std::vector<std::string> Parse(std::string s, char delimiter) {
	std::vector<std::string> data;
	std::string buffer;
	for (size_t i = 0; i < s.length(); ++i) {
		if (s[i] == delimiter) {
			data.push_back(buffer);
			buffer = "";
		}
		else {
			buffer += s[i];
		}
	}
	data.push_back(buffer);

	return data;
}