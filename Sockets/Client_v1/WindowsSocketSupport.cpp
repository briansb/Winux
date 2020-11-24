#include "SocketSupport.h"

// These are Windows-specific routines
#if defined(_WIN32) || defined(_WIN64)


SOCKET sock;

std::string CharToString(char message[], int n) {
	int i = 0;
	std::string s;
	while (i < n) {
		s += message[i++];
	}
	return s;
}

void winuxInitializeSockets() {
	// Start Winsock up
	WSAData wsaData;
	int nCode;
	if ((nCode = WSAStartup(MAKEWORD(1, 1), &wsaData)) != 0) { printf("WSAStartup() returned error code %d\n", nCode); exit(1); }
	return;
}

void winuxCreateSocket() {
	// Create socket - same as Linux
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock == -1) { printf("Could not create socket\n"); exit(1); }
	printf("Socket created\n");
}

void winuxConnect() {
	// Connect - same as Linux
	struct sockaddr_in server;
	server.sin_addr.s_addr = inet_addr("127.0.0.1");
	server.sin_family = AF_INET;
	server.sin_port = htons(4242);
	//Connect to remote server
	if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) { printf("Connect failed. Error.\n"); exit(1); }
	printf("Connected\n");
}

void winuxWriteToServer(std::string s) {
	// Write - same as Linux
	int intBytesSent;
	intBytesSent = send(sock, s.c_str(), (int)s.length(), 0);
	if (intBytesSent < 0) { printf("Send to server failed.\n"); exit(1); }
	return;
}

void winuxReadFromServer(std::string &s) {
	// Read - same as Linux
	char message[1024];
	int intBytesReceived;
	intBytesReceived = recv(sock, message, 1024, 0);
	if (intBytesReceived < 0) { printf("Receive from server failed.\n"); exit(1); }
	s = CharToString(message, intBytesReceived);
	return;
}

#endif
