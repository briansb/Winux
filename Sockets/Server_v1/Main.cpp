
#include "Support.h"
#include "SocketSupport.h"

#include <chrono>
#include <thread>

bool keep_running = true;

int main() {
	//winuxSetKeyboardHandler();  // allows use of ctrl-c for graceful exits

	winuxInitializeSockets();   // only needed for Windows
	winuxCreateSocket();
	winuxBindSocket();
	winuxListen();

	while(1)
	{
		
        winuxAccept();

		winuxCreateClientThread();

	}


	// while(keep_running) {		 
	// 	// pause for a second
	// 	std::this_thread::sleep_for(std::chrono::milliseconds(2000));
	// }
	// winuxShutdown();
	
	return 0;
}