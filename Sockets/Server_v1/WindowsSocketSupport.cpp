#include "SocketSupport.h"

// These are Windows-specific routines
#if defined(_WIN32) || defined(_WIN64)


#include <windows.h>	
#include <winsock.h>
#include <iostream>
#include <string>

#define SD_SEND 1   /* needed for Winsock 1.1 */

#pragma comment (lib, "Ws2_32.lib")

DWORD WINAPI connection_handler(void* sd_);

SOCKET socket_desc, client_sock, *new_sock;
int c;
struct sockaddr_in server, client;

void winuxInitializeSockets() {
    // Start Winsock up - only for Windows
	WSAData wsaData;
	int nCode;
	if ((nCode = WSAStartup(MAKEWORD(1, 1), &wsaData)) != 0) { printf("WSAStartup() returned error code %d\n", nCode); exit(1); }

    c = sizeof(struct sockaddr_in); /* used in accept() */

	return;
}

void winuxCreateSocket() {
    // Create socket - same as Linux
	socket_desc = socket(AF_INET , SOCK_STREAM , 0);
	if (socket_desc == -1) { printf("Could not create socket"); }
	printf("Socket created\n");
    return;
}

void winuxBindSocket() {
    // Bind socket - same as Linux
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons( 4242 );
    int result = bind(socket_desc,(struct sockaddr *)&server , sizeof(server));
    if (result  < 0) { printf("Bind failed\n"); exit(1); }
	printf("Bind done\n");
    return;
}

void winuxListen() {
    // Listen - same as Linux
	listen(socket_desc , 3);
    printf("Listening...\n");
}

void winuxAccept() {
    // Accept - same as Linux
    //client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c);
	client_sock = accept(socket_desc, (struct sockaddr *)&client, &c);
    if (client_sock < 0) { printf("Accept() failed\n"); exit(1); }
	printf("Accepted connection from %s:%d\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));
}


void winuxCreateClientThread() {
	DWORD nThreadID;
	CreateThread(0, 0, connection_handler, (void*)client_sock, 0, &nThreadID);

    return;
}

std::string CharToString(char message[], int n) {
	int i = 0;
	std::string s;
	while (i < n) {
		s += message[i++];
	}
	return s;
}

/* This will handle connection for each client */
DWORD WINAPI connection_handler(void *socket_desc)
{
	//Get the socket descriptor
	SOCKET sock = (SOCKET)socket_desc;
	int read_size;
	char client_message[2000];
	
	
	//Receive a message from client
	std::string strMessage;
	int index;
	std::string ClientID;
	std::string data;
	while( (read_size = recv(sock , client_message , 2000 , 0)) > 0 )
	{
		strMessage = CharToString(client_message, read_size);
		index = (int)strMessage.find_first_of(" ");
		ClientID = strMessage.substr(0,index);
		data = strMessage.substr(index+1,std::string::npos);
		std::cout << "Client PID " << ClientID << " sent data value " << data << std::endl;

		//Send the value, socket number, and PID back to client
		strMessage = data + " " + inet_ntoa(client.sin_addr) + ":" + std::to_string(ntohs(client.sin_port)) + " " + ClientID;
		
		send(sock , strMessage.c_str() , (int)strMessage.length(), 0);
		std::cout << "Sent data value " << data << " from server connection " <<
					inet_ntoa(client.sin_addr) << ":" << std::to_string(ntohs(client.sin_port)) <<
					" to client PID " << ClientID << std::endl << std::endl;				
	}
	
	if(read_size == 0)
	{
		puts("Client disconnected");
		fflush(stdout);
	}
	else if(read_size == -1)
	{
		perror("recv failed");
	}
		
	//Free the socket pointer
	free(socket_desc);
	
	return 0;
}

#endif
