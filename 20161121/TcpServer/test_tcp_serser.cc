#include "TcpServer.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void onConnection(const zx::TcpConnectionPtr &conn)
{
    printf("%s\n", conn->toString().c_str());
    conn->send("hello, welcome to Chat Server.\r\n");
}

void onMessage(const zx::TcpConnectionPtr &conn)
{
    std::string s(conn->receive());
	printf("from client: %s\n", s.c_str());
    conn->send(s);
}

void onClose(const zx::TcpConnectionPtr &conn)
{
    printf("%s close\n", conn->toString().c_str());
}

int main(int argc, char const *argv[])
{
	zx::TcpServer server("192.168.1.97", 9999);
    server.setConnectCallback(&onConnection);
    server.setMessageCallback(&onMessage);
    server.setCloseCallback(&onClose);

    server.start();

    return 0;
}
