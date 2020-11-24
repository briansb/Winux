#ifndef SUPPORT_H
#define SUPPORT_H

#if defined(_WIN32) || defined(_WIN64)
	#include <windows.h>
#elif defined(__linux__)
	#include <unistd.h>
#endif

#include <stdio.h>
#include <string>
#include <algorithm>    // std::replace
#include <signal.h>     // keyboard control handler
#include <fstream>
#include <iostream>

// All stressors use these variables
extern std::string window_title;
extern bool data_logging;


extern bool keep_running;


const char WINDOW_TITLE[] = "Multiplatform Stressor";


void ProcessArguments(int argc, char** argv);
std::string LoseUnderscores(std::string s);

// data logging routines
void OpenFileAndGenerateHeader(std::string filename);
void WriteDataToFile(std::string datapoint, bool endofline = false);
void CloseFile();

// OS-dependent routines
std::string zPlatformIndependence();
void zSetKeyboardHandler();
std::string zGetProcessID();





#endif