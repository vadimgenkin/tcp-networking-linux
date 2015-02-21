/*
 * TcpClient.h
 *
 *  Created on: Feb 17, 2015
 *      Author: vadim
 */

#ifndef TCPCLIENT_H_
#define TCPCLIENT_H_

#include <iostream>
#include <memory>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <string.h>
#include <arpa/inet.h>
#include "NetworkStream.h"

using namespace std;

class TcpClient {
private:
	int _sd;
	string _ip;
	int _port;
public:
	TcpClient(string ip, int port) : _sd(-1), _ip(ip), _port(port) { };
	~TcpClient();
	int Connect(unique_ptr<NetworkStream> &netStream);
};

#endif /* TCPCLIENT_H_ */
