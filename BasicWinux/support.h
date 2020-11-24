#ifndef SUPPORT_H
#define SUPPORT_H

#if defined(_WIN32) || defined(_WIN64)
	#include <windows.h>
#elif defined(__linux__)
	#include <unistd.h>
#endif


#include <string>
//#include <stdio.h>
//#include <algorithm>    // std::replace
//#include <signal.h>     // keyboard control handler
//#include <fstream>
//#include <iostream>

// All stressors use these variables
extern std::string argument_one;

void ProcessArguments(int argc, char** argv);

std::string winuxGetProcessID();
std::string winuxPlatformIndependence();




#endif