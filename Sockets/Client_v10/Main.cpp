
#include "Support.h"
#include "SocketSupport.h"
#include <thread>

 
bool keep_running = true;
std::string strMessageToServer;
std::string strMessageFromServer;

int main()
{
	// seed the random number generator for test data
	srand((int)time(0));

	// set keyboard handler
	winuxSetKeyboardHandler();


	if (winuxInitializeSockets())
		std::cout << "Sockets initialized" << std::endl;
	else { std::cout << "Could not initialize sockets" << std::endl; exit(1); }

	if (winuxCreateSocket())
		std::cout << "Socket created" << std::endl;
	else { std::cout << "Could not create socket" << std::endl; winuxSocketShutdown(); exit(1); }

	if (winuxConnectToSocket())
		std::cout << "Connected to socket" << std::endl;
	else { std::cout << "Could not connect to socket" << std::endl; winuxSocketShutdown(); exit(1); }
	
	while (keep_running) {
		// define a variable message to send to server
		int n = rand() % 1000 + 1;
		strMessageToServer = "Client PID = " + std::to_string(winuxGetPID()) + " client data = " + std::to_string(n);
		if (winuxSendToServer(strMessageToServer)) {
			std::cout << "Sent to server:  " << strMessageToServer << std::endl;
		}
		else {
			std::cout << "Could not send to server" << std::endl;
			break;
		}

		if (winuxReceiveFromServer(strMessageFromServer)) {
			std::cout << "Received from server:  " << strMessageFromServer << std::endl;
		}
		else {
			std::cout << "Could not receive from server" << std::endl;
			break;
		}


		// this is the preferred method
		std::this_thread::sleep_for(std::chrono::milliseconds(2000));
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



