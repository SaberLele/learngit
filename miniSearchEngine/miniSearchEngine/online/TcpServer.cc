 ///
 /// @file    TcpServer.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2015-11-07 10:23:57
 ///

#include "TcpServer.h"

namespace zx
{

TcpServer::TcpServer(unsigned short port)
	: inetAddr_(port),
	  sockfd_(),
	  epollfd_(sockfd_.fd())
{
	sockfd_.ready(inetAddr_);
}

TcpServer::TcpServer(const string & ip, unsigned short port)
: inetAddr_(ip.c_str(), port)
, sockfd_()
, epollfd_(sockfd_.fd())
{
	sockfd_.ready(inetAddr_);
}

void TcpServer::start()
{
	epollfd_.loop();
}

void TcpServer::stop()
{
	epollfd_.unloop();
}

void TcpServer::setConnectionCallback(TcpServerCallback cb)
{
	epollfd_.setConnectionCallback(cb);
}

void TcpServer::setMessageCallback(TcpServerCallback cb)
{
	epollfd_.setMessageCallback(cb);
}

void TcpServer::setCloseCallback(TcpServerCallback cb)
{
	epollfd_.setCloseCallback(cb);
}

}//end of namespace zx
