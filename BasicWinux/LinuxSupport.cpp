#include "support.h"

// These are Linux-specific routines
#if defined(__linux__)

std::string winuxGetProcessID() {
	return std::to_string(getpid());
}

std::string winuxPlatformIndependence() {
	return "Linux";
}


#endif