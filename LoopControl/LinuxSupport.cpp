#include "support.h"

// These are Linux-specific routines
#if defined(__linux__)

std::string zGetProcessID() {
	return std::to_string(getpid());
}

std::string zPlatformIndependence() {
	return "Linux";
}

void CatchInterrupt(int s){
	// 2 - SIGINT - ctrl-c
	// 20 - SIGTSTP - ctrl-z
           printf("Caught signal %d\n",s);
		   keep_running = false;
}
// https://stackoverflow.com/questions/17766550/ctrl-c-interrupt-event-handling-in-linux
// https://stackoverflow.com/questions/1641182/how-can-i-catch-a-ctrl-c-event
void zSetKeyboardHandler() {
	struct sigaction sigIntHandler;
	sigIntHandler.sa_handler = CatchInterrupt;
	sigemptyset(&sigIntHandler.sa_mask);
	sigIntHandler.sa_flags = 0;
	sigaction(SIGINT, &sigIntHandler, NULL);
}


#endif