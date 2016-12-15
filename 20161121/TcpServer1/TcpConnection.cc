 ///
 /// @file    TcpConnection.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-21 05:52:07
 ///

#include "TcpConnection.h"

namespace zx
{

	TcpConnection::TcpConnection(int sockfd)
	:sockfd_(sockfd)
	,sockIO_(sockfd)
	,localAddr_(Socket::getLocalAddr(sockfd))
	,peerAddr_(Socket::getPeerAddr(sockfd))
	,isShutdownWrite_(false)
	{}

	TcpConnection::~TcpConnection()
	{
		if(!isShutdownWrite_)
		{
			shutdown();
		}
	}

	//shared_from_this会从weak_ptr安全的生成一个自身的shared_ptr.
	void TcpConnection::handleConnectCallback()
	{
		if(onConnectCallback_)
		{
			onConnectCallback_(shared_from_this());
		}
	}

	void TcpConnection::handleMessageCallback()
	{
		if(onMessageCallback_)
		{
			onMessageCallback_(shared_from_this());
		}
	}

	void TcpConnection::handleCloseCallback()
	{
		if(onCloseCallback_)
		{
			onCloseCallback_(shared_from_this());
		}
	}

	ssize_t TcpConnection::readn(char *buf, size_t count)
	{
		ssize_t ret = sockIO_.readn(buf,count);
		if(ret==-1)
		{
			fprintf(stderr, "TcpConnection readn\n");
			exit(EXIT_FAILURE);
		}
		return ret;
	}

	ssize_t TcpConnection::writen(const char *buf, size_t count)
	{
		ssize_t ret=sockIO_.writen(buf, count);
		if(ret == -1)
		{
			fprintf(stderr, "TcpConnection writen\n");
			exit(EXIT_FAILURE);
		}
		return ret;
	}

	ssize_t TcpConnection::readLine(char *usrbuf, size_t maxlen)
	{
		ssize_t ret = sockIO_.readline(usrbuf, maxlen);
		if(ret == -1)
		{
			fprintf(stderr, "TcpConnection readLine\n");
			exit(EXIT_FAILURE);
		}
		return ret;
	}

	std::string TcpConnection::receive()
	{
		char str[65535]={0};
		int ret=readLine(str,sizeof str);
		if(ret==0)
		{
			return std::string();
		}
		else
		{
			return std::string(str);
		}
	}

	void TcpConnection::send(const std::string & s)
	{
		writen(s.c_str(), s.size());	
	}

	std::string TcpConnection::toString() const
	{
		char text[100];
		snprintf(text,sizeof text, "%s:%d -> %s:%d",
				localAddr_.toIp().c_str(),
				localAddr_.toPort(),
				localAddr_.toIp().c_str(),
				localAddr_.toPort());
		return text;
	}

}//end of namespace zx
