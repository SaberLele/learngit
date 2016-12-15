#include "TcpServer.h"


namespace
{
int createSocketFd()
{
    int fd = ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(fd == -1)
    {
        fprintf(stderr, "create socket fd error\n");
        exit(EXIT_FAILURE);
    }

    return fd;
}
}


namespace zx
{
TcpServer::TcpServer(const string & ip, unsigned short port)
: addr_(ip, port)
, sockfd_(createSocketFd())
, poller_(sockfd_.fd())
{
    sockfd_.setTcpNoDelay(false);
    sockfd_.setReusePort(true);
    sockfd_.setReuseAddr(true);
    sockfd_.setKeepAlive(false);

    sockfd_.bindAddress(addr_);
    sockfd_.listen();
}

}
