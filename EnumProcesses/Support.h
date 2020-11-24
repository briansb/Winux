#ifndef SUPPORT_H
#define SUPPORT_H

#if defined(_WIN32) || defined(_WIN64)
	#include <windows.h>
#elif defined(__linux__)
	#include <unistd.h>
#endif


#include <string>


// All stressors use these variables
extern std::string argument_one;

void ProcessArguments(int argc, char** argv);

std::string winuxGetProcessID();
std::string winuxPlatformIndependence();
void winuxGetNamesAndProcessIDs();


#endif