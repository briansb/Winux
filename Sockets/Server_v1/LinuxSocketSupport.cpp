#include "SocketSupport.h"

// These are Linux-specific routines
#if defined(__linux__)


//#include <string.h>	//strlen
//#include <stdlib.h>	//strlen
//#include <string>
//#include <sys/socket.h>
//#include <pthread.h> //for threading , link with lpthread


//the thread function
void *connection_handler(void *);

//int socket_desc , client_sock , c , *new_sock;
int client_sock;
int socket_desc, c, *new_sock;
struct sockaddr_in server , client;

void winuxInitializeSockets() {
    c = sizeof(struct sockaddr_in); /* used in accept() */
    return;
}

void winuxCreateSocket() {
    // Create socket - same as Windows
	socket_desc = socket(AF_INET , SOCK_STREAM , 0);
	if (socket_desc == -1) { printf("Could not create socket"); exit(1);}
	printf("Socket created\n");
    return;
}

void winuxBindSocket() {
    // Bind socket - same as Windows
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons( 4242 );
    int result = bind(socket_desc,(struct sockaddr *)&server , sizeof(server));
    if (result  < 0) { printf("Bind failed\n"); exit(1); }
	printf("Bind done\n");
    return;
}

void winuxListen() {
    // Listen - same as Windows
	listen(socket_desc , 3);
    printf("Listening...\n");
}

void winuxAccept() {
    // Accept - same as Windows
    client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c);
    if (client_sock < 0) { printf("Accept() failed\n"); exit(1); }
	printf("Accepted connection from %s:%d\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));
}

void winuxCreateClientThread() {
    pthread_t sniffer_thread;
	new_sock = (int*)malloc(1);
	*new_sock = client_sock;
		
	if( pthread_create( &sniffer_thread , NULL ,  connection_handler , (void*) new_sock) < 0) { printf("Could not create thread\n"); exit(1); }
		
	//Now join the thread , so that we dont terminate before the thread
	//pthread_join( sniffer_thread , NULL);
	printf("Thread ID created\n");

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
void *connection_handler(void *socket_desc)
{
	//Get the socket descriptor
	int sock = *(int*)socket_desc;
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
		index = strMessage.find_first_of(" ");
		ClientID = strMessage.substr(0,index);
		data = strMessage.substr(index+1,std::string::npos);
		std::cout << "Client PID " << ClientID << " sent data value " << data << std::endl;

		//Send the value, socket number, and PID back to client
		strMessage = data + " " + inet_ntoa(client.sin_addr) + ":" 
					+ std::to_string(ntohs(client.sin_port)) + 
					" " + ClientID;
		write(sock , strMessage.c_str() , strMessage.length());
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