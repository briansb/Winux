#include <string>

std::string PrintBuffer(char *ptr, int n) {
	std::string s;
	for (int i = 0; i < n; ++i)
		s += *ptr++;
	return s;
}