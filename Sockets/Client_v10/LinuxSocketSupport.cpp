#include "SocketSupport.h"

// These are Linux-specific routines
#if defined(__linux__)
	#include <sys/socket.h>  // for AF_INET, SOCK_STREAM
	#include <arpa/inet.h>   // for struct sockaddr_in
	#include <unistd.h>
	#include <string.h>	//strlen

int client_socket;

bool winuxInitializeSockets() { 
	// not needed for Linux
	return true; }

bool winuxCreateSocket() {
	// Linux
	// socket() creates an endpoint for communication and returns a descriptor.
	// AF_INET = 2, The Internet Protocol version 4 (IPv4) address family.
	// SOCK_STREAM = 1, A socket type that provides sequenced, reliable, two-way, connection-based byte streams with an OOB (out of band) data transmission mechanism. This socket type uses the Transmission Control Protocol (TCP) for the Internet address family.
	// The protocol specifies a particular protocol to be used with the socket. Normally only a single protocol exists to support a particular socket type within a given protocol family, in which case protocol can be specified as 0
	// On success, a file descriptor for the new socket is returned. On error, -1 is returned, and errno is set appropriately.
	client_socket = socket(AF_INET, SOCK_STREAM, 0);
	if (client_socket == -1) {
		std::cout << "Socket not created.  CreateSocket() returned error code " << client_socket << std::endl;
		return false;
	}
	return true;
}

bool winuxConnectToSocket() {
	// Windows
	// If no error occurs, connect returns zero. 
	// Otherwise, it returns SOCKET_ERROR, and a specific error code can be retrieved by calling WSAGetLastError.
	// Linux
	// The connect() system call connects the socket referred to by the file descriptor sockfd to the address specified by addr.  
	// The addrlen argument specifies the size of addr. 
	// If the connection or binding succeeds, zero is returned.  On error, -1 is returned, and errno is set appropriately.
	const char* host = "127.0.0.1";
	int intPort = 4242;
	u_long ulRemoteAddress = inet_addr(host);
	sockaddr_in sa_inServer;
	sa_inServer.sin_family = AF_INET;
	sa_inServer.sin_addr.s_addr = ulRemoteAddress;
	sa_inServer.sin_port = (u_short)htons(intPort);
	int result = connect(client_socket, (sockaddr*)&sa_inServer, sizeof(sockaddr_in));
	if (result < 0) {
		std::cout << "Could not connect to socket.  ConnectToSocket() returned error code " << result << std::endl;
		return false;
	}
	return true;
}

bool winuxSendToServer(std::string s) {
	// Linux
	// The system calls send(), sendto(), and sendmsg() are used to transmit a message to another socket.
	int bytes_sent = send(client_socket, s.c_str(), (int)s.length(), 0);
	if (bytes_sent < 0) {
		std::cout << "Could not send to server.  SendToServer() returned error code " << bytes_sent << std::endl;
		return false;
	}
	return true;
}

bool winuxReceiveFromServer(std::string &strMessageFromServer) {
	// Read reply from server
	char buffer[1024];
	int bytes_received = recv(client_socket, buffer, 1024, 0);
	if (bytes_received < 0) {
		std::cout << "Receive from server error" << std::endl;
		return false;
	}
	else if (bytes_received == 0) {
		std::cout << "Server unexpectedly closed connection" << std::endl;
		return false;
	}
	else if (bytes_received < 0) {
		std::cout << "Could not receive from server.  ReceiveFromServer() returned error code " << bytes_received << std::endl;
		return false;
	}
	strMessageFromServer = PrintBuffer(buffer, bytes_received);
	return true;

}

bool winuxSocketShutdown() {
	// not needed in Linux
	return true;
}
#endif