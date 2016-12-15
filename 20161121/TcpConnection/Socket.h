#ifndef SOCKET_H_
#define SOCKET_H_

#include "Noncopyable.h"
#include "InetAddress.h"

namespace wd
{
class Socket : Noncopyable
{
public:
    explicit Socket(int sockfd);
    ~Socket();


	void ready(const InetAddress &);

    int fd() const { return sockfd_; }
    void bindAddress(const InetAddress &addr);
    void listen();
    int accept();

    void shutdownWrite();

    void setTcpNoDelay(bool on);
    void setReuseAddr(bool on);
    void setReusePort(bool on);
    void setKeepAlive(bool on);


    //static
    static InetAddress getLocalAddr(int sockfd);
    static InetAddress getPeerAddr(int sockfd);

private:
    const int sockfd_;
};

}//end of namespace wd

#endif //SOCKET_H_
