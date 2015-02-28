/*
 * NetworkStream.h
 *
 *  Created on: Feb 17, 2015
 *      Author: vadim
 */

#ifndef NETWORKSTREAM_H_
#define NETWORKSTREAM_H_

#include <unistd.h>
#include <memory>

class NetworkStream {
private:
	int _sd;

	//private, since it should be constructed only by TcpClient and TcpListener
	NetworkStream(int sd) : _sd{sd} { };
public:
	int Read(unsigned char *buf, size_t len);
	int Write(const unsigned char *buf, size_t len);
	~NetworkStream() { close(_sd); };

	//TcpClient and TcpListener should get access to private members
	friend class TcpClient;
	friend class TcpListener;
};

#endif /* NETWORKSTREAM_H_ */
