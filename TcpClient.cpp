/*
 * TcpClient.cpp
 *
 *  Created on: Feb 17, 2015
 *      Author: vadim
 */

#include "TcpClient.h"

NetworkStream TcpClient::Connect()
{
	_sd = socket(AF_INET, SOCK_STREAM, 0); //AF_INET - ipv4, SOCK_STREAM - tcp, 0 - ip protocol

	if(_sd == -1)
		return NetworkStream{-1};

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(_port);
    addr.sin_addr.s_addr = inet_addr(_ip.c_str());

    if(addr.sin_addr.s_addr == INADDR_NONE)
    {
    	perror("bad ip address");
    	return NetworkStream{-1};
    }

    int result = connect(_sd, (struct sockaddr*)&addr, sizeof(addr));
    if(result == -1)
    {
    	perror("failed in connect()");
    	return NetworkStream{-1};
    }

    return NetworkStream{_sd};
}


TcpClient::~TcpClient() {
	// TODO Auto-generated destructor stub
}
