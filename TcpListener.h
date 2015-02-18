/*
 * TcpListener.h
 *
 *  Created on: Feb 17, 2015
 *      Author: vadim
 */

#ifndef TCPLISTENER_H_
#define TCPLISTENER_H_

#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <string.h>
#include "NetworkStream.h"

class TcpListener {
private:
	int _port;
	int _sd;

public:
	TcpListener(int port) : _port{port}, _sd{0} { };
	~TcpListener();
	int Start();
	NetworkStream AcceptTcpClient();
};

#endif /* TCPLISTENER_H_ */
