/*  
Tried various things with socket shutdown
and interrupts
*/

// https://tangentsoft.net/wskfaq/
// https://www.studytonight.com/network-programming-in-python/working-with-tcp-sockets
// excellent resources for both client and server

#include "Support.h"
#include "SocketSupport.h"
#include <thread>

bool keep_running = true;
std::string strMessageToServer;
std::string strMessageFromServer;


int main()
{
	// set keyboard handler
	winuxSetKeyboardHandler();

	if (winuxInitializeSockets())
		std::cout << "Sockets initialized" << std::endl;
	else { std::cout << "Could not initialize sockets" << std::endl; exit(1); }

	if (winuxCreateSocket())
		std::cout << "Socket created" << std::endl;
	else { std::cout << "Could not create socket" << std::endl; winuxSocketShutdown(); exit(1); }

	if (winuxBindToSocket())
		std::cout << "Socket bind successful" << std::endl;
	else { std::cout << "Could not bind to socket" << std::endl; winuxSocketShutdown(); exit(1); }

	if (winuxListenOnSocket())
		std::cout << "Listening..." << std::endl;
	else { std::cout << "Can't hear a thing" << std::endl; winuxSocketShutdown(); exit(1); }

	while (keep_running) {

		#if defined(_WIN32) || defined(_WIN64)
		SOCKET client_sock = winuxAcceptConnection();
		if (client_sock == INVALID_SOCKET) {
			std::cout << "Did not accept connection" << std::endl;
		}
		else {
			std::cout << "Accepted connection with client socket " << client_sock << std::endl;
			if (StartThread(client_sock)) {}
			else std::cout << "Could not start thread" << std::endl;
		}
		#elif defined(__linux__)
		int client_sock = winuxAcceptConnection();
		if (client_sock < 0) {
			std::cout << "Did not accept connection" << std::endl;
		}
		else {
			std::cout << "Accepted connection with client socket " << client_sock << std::endl;
			if (StartThread(client_sock)) {}
			else std::cout << "Could not start thread" << std::endl;
		}
		#endif

		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}

	if (winuxSocketShutdown()) {
		std::cout << "Normal shutdown.  Press Enter to exit" << std::endl;
	}
	else {
		std::cout << "Abnormal shutdown.  Press Enter to exit" << std::endl;
	}

	std::cin.get();


	return 0;
}
