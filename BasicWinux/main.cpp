
#include "OS_Specific.h"
#include "support.h"



/*  MODEL FOR PLATFORM INDEPENDENCE */
//void CreateDelay(int Delaycount)
//{
//#if defined(_WIN32) || defined(_WIN64)
//	Sleep(Delaycount);
//#elif defined(__linux__)
//	usleep(Delaycount);
//#endif
//}

#include <iostream>
//#include <chrono>
//#include <thread>
//#include <iomanip>
//#include <ctime>


std::string argument_one;


int main(int argc, char** argv)
{

	// determine OS
	std::string OS = GetOSname();
	
	std::cout << "The OS platform is " << OS << std::endl;
	if (OS != "Windows 64-bit" && OS != "Windows 32-bit" && OS != "Linux") {
		std::cout << "No can do with this OS." << std::endl;
		return 1;
	}

	// assign the command line arguments to variables...this will vary among stressors
	ProcessArguments(argc, argv);
	std::cout << "The command line argument is " << argument_one << std::endl;

	std::cout << "Running with PID = " << winuxGetProcessID() << " (" << winuxPlatformIndependence() << ")" << std::endl;
	//	// Windows - GetCurrentProcessId()
	//	// Linux - getpid()

	
	return 0;
}

