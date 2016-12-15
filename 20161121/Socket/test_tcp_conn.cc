 ///
 /// @file    test_tcp_conn.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-21 06:13:24
 ///

#include "Socket.h"
#include "TcpConnection.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>

int main()
{
	int fd=::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if(fd==-1)
	{
		perror("create socket error");
		exit(EXIT_FAILURE);
	}

	zx::InetAddress addr("192.168.1.97", 8888);

	zx::Socket sock(fd);
	sock.ready(addr);

	int peerfd = sock.accept();

	zx::TcpConnectionPtr conn(new zx::TcpConnection(peerfd));
	std::cout << conn->toString() << "has connected" << std::endl;

	while(1)
	{
		std::string msg(conn->receive());
		std::cout << msg << std::endl;
		conn->send(msg);
	}

	conn->shutdown();
	close(fd);

	return 0;
}
