#include "Support.h"
#include "SocketSupport.h"

// These are Linux-specific routines
#if defined(__linux__)

void CatchInterrupt(int s) {
	// 2 - SIGINT - ctrl-c
	// 20 - SIGTSTP - ctrl-z
	switch (s) {
	case 2:
		printf("Ctrl-C event\n\n");
		keep_running = false;
		break;
	case 20:
		printf("Ctrl-Z event\n\n");
		keep_running = false;
		winuxSocketShutdown();
	}
}

// https://stackoverflow.com/questions/17766550/ctrl-c-interrupt-event-handling-in-linux
// https://stackoverflow.com/questions/1641182/how-can-i-catch-a-ctrl-c-event
void winuxSetKeyboardHandler() {
	struct sigaction sigIntHandler;
	sigIntHandler.sa_handler = CatchInterrupt;
	sigemptyset(&sigIntHandler.sa_mask);
	sigIntHandler.sa_flags = 0;
	sigaction(SIGINT, &sigIntHandler, NULL);
}

int winuxGetPID() {
	return getpid();
}

#endif