#ifndef SOCKETSUPPORT_H
#define SOCKETSUPPORT_H

#include <stdio.h>   //  printf, etc.
#include <stdlib.h>  //  exit(), srand(), rand()
#include <string>


#if defined(_WIN32) || defined(_WIN64)
	#include <windows.h>
	#pragma comment (lib, "Ws2_32.lib")

#elif defined(__linux__)
	#include <sys/socket.h>  // for AF_INET, SOCK_STREAM
	#include <arpa/inet.h>   // for struct sockaddr_in
	#include <unistd.h>
	//#include <string.h>	//strlen

#endif



void winuxInitializeSockets();
void winuxCreateSocket();
void winuxConnect();
void winuxWriteToServer(std::string s);
void winuxReadFromServer(std::string &s);



#endif