/*
 * TcpListener.cpp
 *
 *  Created on: Feb 17, 2015
 *      Author: vadim
 */

#include "TcpListener.h"

TcpListener::~TcpListener() {
	if(_sd > 0) close(_sd); //close the socket if it was opened
}

int TcpListener::Start()
{
	_sd = socket(AF_INET, SOCK_STREAM, 0); //AF_INET - ipv4, SOCK_STREAM - tcp, 0 - ip protocol

	if(_sd == -1)
		return -1;

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(_port);

    int optval = 1;
    int result = setsockopt(_sd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof optval);
    if(result != 0)
    	return result;

    result = bind(_sd, (struct sockaddr*)&addr, sizeof(addr));
    if (result != 0) {
    	return result;
    }
    result = listen(_sd, 5);
    if (result != 0)
    	return result;

	return 0;
}

int TcpListener::AcceptTcpClient(NetworkStream **netStream)
{
	struct sockaddr_in addr;

	socklen_t addr_len = sizeof(addr);
	int new_sd = accept(_sd, (struct sockaddr *) &addr, &addr_len);

	if(new_sd < 0)
	{
		perror("failed in accept()");
		return -1;
	}

	*netStream = new NetworkStream(new_sd);
	return 0;
}
