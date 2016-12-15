 ///
 /// @file    Socket.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-20 18:24:42
 ///

#include "Socket.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/tcp.h>
#include <netdb.h>

namespace zx
{

	Socket::Socket(int sockfd)
	:sockfd_(sockfd)
	{
	}

	Socket::~Socket()
	{
		::close(sockfd_);
	}

	void Socket::ready(const InetAddress & inetAddr)
	{
		setReuseAddr(true);
		setReusePort(true);
		setKeepAlive(false);
		setTcpNoDelay(false);
		bindAddress(inetAddr);
		listen();
	}

	void Socket::bindAddress(const InetAddress &addr)
	{
		if(::bind(sockfd_, (struct sockaddr*)addr.getSockAddrInet(), sizeof(addr)) == -1)
		{
			fprintf(stderr, "bind address error\n");
			exit(EXIT_FAILURE);
		}
	}

	void Socket::listen()
	{
		if(::listen(sockfd_, SOMAXCONN) == -1)
		{
			 fprintf(stderr, "listen address error\n");
			 exit(EXIT_FAILURE);
		}
	}

	int Socket::accept()
	{
		int fd = ::accept(sockfd_, NULL, NULL);
		if(fd==-1)
		{
			fprintf(stderr, "accept error\n");
			exit(EXIT_FAILURE);
		}
		return fd;
	}

	void Socket::shutdownWrite()
	{
		if(::shutdown(sockfd_, SHUT_WR) == -1)
		{
			fprintf(stderr, "shutdown error\n");
			exit(EXIT_FAILURE);
		}
	}

	//不设置TcpNoDelay：发送数据包比较小时，内核会根据数据包的大小有一定延迟，
	//要至少到达一定的字节才发送出去；
	//如果设置了之后，只要有write数据包进来，马上就可以发出去；
	void Socket::setTcpNoDelay(bool on)
	{
		int optval = on ? 1 : 0;
		if(::setsockopt(sockfd_,
						IPPROTO_TCP,
						TCP_NODELAY,
						&optval,
						static_cast<socklen_t>(sizeof optval)) == -1)
		{
			fprintf(stderr, "setTcpNoDelay error\n");
			exit(EXIT_FAILURE);
		}
	}

	//重复利用网络地址，重复打开关闭服务程序不会报错；
	void Socket::setReuseAddr(bool on)
	{
		int optval = on ? 1 : 0;
		if(::setsockopt(sockfd_,
						SOL_SOCKET,
						SO_REUSEADDR,
						&optval,
						static_cast<socklen_t>(sizeof optval)) == -1)
		{
			fprintf(stderr, "setReuseAddr error\n");
			exit(EXIT_FAILURE);
		}
	}
	
	//可以同时启用多个同样的服务端，复用同个端口号
	void Socket::setReusePort(bool on)
	{
	//内核版本比较高的情况下才有定义SO_RESUSEPORT；
	#ifdef SO_REUSEPORT
		int optval = on ? 1 : 0;
		int ret= ::setsockopt(sockfd_,
						SOL_SOCKET,
						SO_REUSEPORT,
						&optval,
						static_cast<socklen_t>(sizeof optval));
		if(ret<0)
		{
			fprintf(stderr, "setReusePort error\n");
			exit(EXIT_FAILURE);
		}
	#else
		//内核版本比较低执行这段代码，不执行上面的代码
		if(on)
		{
			fprintf(stderr, "SO_REUSEPORT is not supported.\n");
		}
	#endif
	}

	//测试客户端链接是否在线（心跳包）
	void Socket::setKeepAlive(bool on)
	{
		int optval = on ? 1 : 0;
		if(::setsockopt(sockfd_,
						SOL_SOCKET,
						SO_KEEPALIVE,
						&optval,
						static_cast<socklen_t>(sizeof optval)) == -1)
		{
			fprintf(stderr, "setKeepAlive error\n");
			exit(EXIT_FAILURE);
		}
	}

	InetAddress Socket::getLocalAddr(int sockfd)
	{
		struct sockaddr_in addr;
		socklen_t len=sizeof(addr);

		if(::getsockname(sockfd,
						(struct sockaddr*)&addr,
						&len) == -1)
		{
			fprintf(stderr, "getLocalAddress\n");
			exit(EXIT_FAILURE);
		}
		return InetAddress(addr);
	}

	InetAddress Socket::getPeerAddr(int sockfd)
	{
		struct sockaddr_in addr;
		socklen_t len=sizeof addr;
		if(::getpeername(sockfd,
						(struct sockaddr*)&addr,
						&len)==-1)
		{
			fprintf(stderr, "getPeerAddress\n");
			exit(EXIT_FAILURE);
		}
		return InetAddress(addr);
	}
}//end of namespace zx
