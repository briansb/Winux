//  For Windows, turn off use of precompiled headers
//  Project Properties -> C/C++ -> Precompiled Headers -> Not Using Precompiled Headers

#include "OS_Specific.h"
#include "stress_test.h"
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


#include <chrono>
#include <thread>
#include <iomanip>
#include <ctime>


std::string window_title;
bool data_logging = false;

bool keep_running = true;


// commmand line arguments are, in order:
//    Window title
//    true or other (log data to csv or none)
//    ....and other
int main(int argc, char** argv)
{
	std::cout << "Multiplatform stressor template" << std::endl;

	// determine OS
	std::string OS = GetOSname();
	std::cout << "The OS platform is " << OS << std::endl;
	if (OS != "Windows 64-bit" && OS != "Windows 32-bit" && OS != "Linux") {
		std::cout << "No can do with this OS." << std::endl;
		return 1;
	}

	// assign the command line arguments to variables...this will vary among stressors
	ProcessArguments(argc, argv);

	std::cout << "The window title is " << window_title << std::endl;

	std::cout << "Data logging is " << data_logging << std::endl;
	if (data_logging) OpenFileAndGenerateHeader(window_title);
	
	// set keyboard handler
	zSetKeyboardHandler();


	// main loop
	while (keep_running) {
		// need system time here
		if (data_logging) WriteDataToFile("time index");

		std::cout << "Running with PID = " << zGetProcessID() << " (" << zPlatformIndependence() << ")" << std::endl;
		// Windows - GetCurrentProcessId()
		// Linux - getpid()

		// this is the preferred method
		std::this_thread::sleep_for(std::chrono::milliseconds(2000));

		// need data point here
		//if (data_logging) WriteToCSV("y-value", true);
		if (data_logging) WriteDataToFile("data value", true);

		//keep_running = false;  // set this false to run one loop at a time
	} // end of main loop

	std::cout << "Normal exit, keep_running = " << keep_running << std::endl;
	std::cout << "Press Enter to exit" << std::endl;
	std::cin.get();

	if (data_logging) CloseFile();
	
	return 0;
}

