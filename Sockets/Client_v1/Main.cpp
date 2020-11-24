
#include "Support.h"
#include "SocketSupport.h"

#include <chrono>
#include <thread>
//#include <processthreadsapi.h>

bool keep_running = true;

int main()
{
	winuxSetKeyboardHandler();  // allows use of ctrl-c for graceful exits
	winuxInitializeSockets();   // only needed for Windows
	winuxCreateSocket();
	winuxConnect();

	
	std::string message;
	srand((int)time(0));    // only for demo
	int data;				// only for demo
	int PID;				// only for demo
	std::string conn_info;	// only for demo
	int index1, index2;  	// only for demo

	while(keep_running) {
		 
		// send PID and random integer to server
		data = rand() % 100 + 1;
		PID = winuxGetPID();
		message = std::to_string(PID) + " " + std::to_string(data);
		printf("Sent data %d to server from PID %d\n", data, PID);
		winuxWriteToServer(message);

		// receive same random integer, connection info, and PID
		winuxReadFromServer(message);
		index1 = (int)message.find_first_of(" ");
		data = std::stoi(message.substr(0, index1));
		index2 = (int)message.find_first_of(" ", index1 + 1);
		conn_info = message.substr(index1 + 1, index2 - index1 - 1);
		PID = std::stoi(message.substr(index2 + 1, std::string::npos));
		printf("Received value %d from server connection %s for client PID %d\n\n", 
			data, conn_info.c_str(), PID);

		// pause for a second
		std::this_thread::sleep_for(std::chrono::milliseconds(2000));

	}

	// need better shutdown?
	printf("shutdown()\n");
    
	return 0;
}



