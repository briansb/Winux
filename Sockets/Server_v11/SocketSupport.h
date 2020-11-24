#ifndef SOCKETSUPPORT_H
#define SOCKETSUPPORT_H

#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
SOCKET winuxAcceptConnection();
bool StartThread(SOCKET sock);
DWORD WINAPI ReadAndWriteToClient(void* local_socket);
void ClientShutdown(SOCKET sd);

#elif defined(__linux__)
int winuxAcceptConnection();
bool StartThread(int sock);
void *ReadAndWriteToClient(void* local_socket);
void ClientShutdown();
#endif


#include <string>
#include <iostream>
#include <vector>
//#include <algorithm>


// writes a character buffer to a string
std::string BufferToString(char CharBuffer[], int buffer_size);

//parses incoming data
std::vector<std::string> Parse(std::string s, char delimiter);

bool winuxInitializeSockets();
bool winuxCreateSocket();
bool winuxBindToSocket();
bool winuxListenOnSocket();



bool winuxSocketShutdown();

#endif