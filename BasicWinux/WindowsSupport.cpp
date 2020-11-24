#include "support.h"

// These are Windows-specific routines
#if defined(_WIN32) || defined(_WIN64)

std::string winuxGetProcessID() {
	return std::to_string(GetCurrentProcessId());
}

std::string winuxPlatformIndependence() {
	return "Windows";
}


#endif