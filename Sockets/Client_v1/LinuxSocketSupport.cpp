#include "SocketSupport.h"

// These are Linux-specific routines
#if defined(__linux__)


//  	char message[1000], server_reply[2000];

int sock;

std::string CharToString(char message[], int n) {
	int i = 0;
	std::string s;
	while (i < n) {
		s += message[i++];
	}
	return s;
}

void winuxInitializeSockets() {
	return;   	// nothing to do in Linux
}

void winuxCreateSocket() {
	//Create socket - same as Windows
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock == -1) 	{ printf("Could not create socket\n"); exit(1); }
	printf("Socket created\n");
}

void winuxConnect() {
	//Connect - same as Windows
	struct sockaddr_in server;
	server.sin_addr.s_addr = inet_addr("127.0.0.1");
	server.sin_family = AF_INET;
	server.sin_port = htons(4242);
	//Connect to remote server
	if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) { printf("Connect failed. Error.\n"); exit(1); }
	printf("Connected\n");

}

void winuxWriteToServer(std::string s) {
	// Write - same as Windows
	int intBytesSent;
	intBytesSent = send(sock, s.c_str(), (int)s.length(), 0);
	if (intBytesSent < 0) { printf("Send to server failed.\n"); exit(1); }
	return;
}

void winuxReadFromServer(std::string &s) {
	// Read - same as Windows
	char message[1024];
	int intBytesReceived;
	intBytesReceived = recv(sock, message, 1024, 0);
	if (intBytesReceived < 0) { printf("Receive from server failed.\n"); exit(1); }
	s = CharToString(message, intBytesReceived);
	return;
}

#endif