#ifndef SOCKETSUPPORT_H
#define SOCKETSUPPORT_H

#include <stdio.h>
#include <iostream>
#include <string>

#if defined(_WIN32) || defined(_WIN64)
	#include <windows.h>
	#include <winsock.h>

#elif defined(__linux__)
	#include <arpa/inet.h>	//inet_addr
	#include <unistd.h>	    //write

#endif


void winuxInitializeSockets();
void winuxCreateSocket();
void winuxBindSocket();
void winuxListen();
void winuxAccept();
void winuxCreateClientThread();

#endif