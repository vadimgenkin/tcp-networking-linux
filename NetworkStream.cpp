/*
 * NetworkStream.cpp
 *
 *  Created on: Feb 17, 2015
 *      Author: vadim
 */

#include "NetworkStream.h"

int NetworkStream::Read(unsigned char *buf, const unsigned int len)
{
	return read(_sd, buf , len);
}

int NetworkStream::Write(const unsigned char *buf, const unsigned int len)
{
	return write(_sd, buf, len);
}
