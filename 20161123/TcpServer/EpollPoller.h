#ifndef EPOLL_POLLER_H
#define EPOLL_POLLER_H

#include "Noncopyable.h"
#include <vector>
#include <map>
#include <sys/epoll.h>
#include "TcpConnection.h"
#include "MutexLock.h"
#include <functional>

namespace zx
{

class EpollPoller : Noncopyable
{
public:
    typedef TcpConnection::TcpConnectionCallback EpollCallback;
	typedef std::function<void()> Functor;

    explicit EpollPoller(int listenfd);
    ~EpollPoller();

    void loop(); //启动epoll
    void unloop(); //关闭epoll

	void runInLoop(const Functor & cb);
	void doPendingFunctors();

	void wakeup();   //唤醒操作，write一个计数器的值给内核
	void handleRead(); //读取计数
#if 1
	//建立新链接的时候，设置一个函数对象，做定制化的操作（回调函数）
    void setConnectCallback(EpollCallback cb)
    { onConnectCallback_ = std::move(cb); }
	//旧链接数据处理
    void setMessageCallback(EpollCallback cb)
    { onMessageCallback_ = std::move(cb); }
	//链接断开的函数回调
    void setCloseCallback(EpollCallback cb)
    { onCloseCallback_ = std::move(cb); }
#endif
private:
    void waitEpollFd(); //循环
    void handleConnection(); //处理accept(处理新接收的链接) 
    void handleMessage(int peerfd); //处理msg（处理旧链接）


    const int epollfd_;
    const int listenfd_; //main函数中直接将Socket类的监听描述符fd传进来
    int wakeupfd_;   //(eventfd)
	bool isLooping_; //是否在运行
	
	MutexLock mutex_;
	std::vector<Functor> pendingFunctors_;
	
    typedef std::vector<struct epoll_event> EventList;
    EventList events_;  //保存活跃的fd

    typedef std::map<int, TcpConnectionPtr> ConnectionList;
    ConnectionList lists_; //实现fd到conn的映射

    EpollCallback onConnectCallback_;
    EpollCallback onMessageCallback_;
    EpollCallback onCloseCallback_;
};

}//end namespace zx

#endif //EPOLL_POLLER_H
