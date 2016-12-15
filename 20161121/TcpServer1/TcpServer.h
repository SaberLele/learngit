#ifndef TCP_SERVER_H
#define TCP_SERVER_H

#include "Noncopyable.h"
#include "EpollPoller.h"
#include "Socket.h"
#include <string>

using std::string;

namespace zx
{
class TcpServer : Noncopyable
{
public:
    typedef EpollPoller::EpollCallback TcpServerCallback;

	TcpServer(const string & ip, unsigned short port);

    void start()
    { poller_.loop(); }

    void setConnectCallback(TcpServerCallback cb)
    { poller_.setConnectCallback(std::move(cb)); }
    void setMessageCallback(TcpServerCallback cb)
    { poller_.setMessageCallback(std::move(cb)); }
    void setCloseCallback(TcpServerCallback cb)
    { poller_.setCloseCallback(std::move(cb)); }

private:
	InetAddress addr_;
    Socket sockfd_;
    EpollPoller poller_;
};

}


#endif //TCP_SERVER_H
