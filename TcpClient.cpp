/*
 * TcpClient.cpp
 *
 *  Created on: Feb 17, 2015
 *      Author: vadim
 */

#include "TcpClient.h"

int TcpClient::Connect(unique_ptr<NetworkStream> &netStream)
{
	_sd = socket(AF_INET, SOCK_STREAM, 0); //AF_INET - ipv4, SOCK_STREAM - tcp, 0 - ip protocol

	if(_sd == -1)
	{
		perror("error opening socket()");
		return -1;
	}

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(_port);
    addr.sin_addr.s_addr = inet_addr(_ip.c_str());

    if(addr.sin_addr.s_addr == INADDR_NONE)
    {
    	perror("bad ip address");
    	return -1;
    }

    int result = connect(_sd, (struct sockaddr*)&addr, sizeof(addr));
    if(result == -1)
    {
    	perror("failed in connect()");
    	return -1;
    }

    netStream.reset(new NetworkStream{_sd});
    return 0;
}


TcpClient::~TcpClient() {
	if(_sd != -1)
	{
		close(_sd);
	}
}
