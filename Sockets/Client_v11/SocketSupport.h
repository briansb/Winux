#ifndef SOCKETSUPPORT_H
#define SOCKETSUPPORT_H


#include <iostream>
#include <string>

std::string PrintBuffer(char *ptr, int n);

bool winuxInitializeSockets();
bool winuxCreateSocket();
bool winuxConnectToSocket();

bool winuxSendToServer(std::string strMessageToServer);
bool winuxReceiveFromServer(std::string &strMessageFromServer);

bool winuxSocketShutdown();


#endif