 ///
 /// @file    EpollPoller.h
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-21 07:10:24
 ///

#ifndef __EPOLLPOLLER_H__
#define __EPOLLPOLLER_H__

#include "Noncopyable.h"
#include "TcpConnection.h"
#include <vector>
#include <map>
#include <sys/epoll.h>

namespace zx
{

	class EpollPoller
	:Noncopyable
	{
		public:
			typedef TcpConnection::TcpConnectionCallback EpollCallback;

			explicit EpollPoller(int listenfd);
			~EpollPoller();

			void loop();   //启动epoll
			void unloop(); //关闭epoll

			void setConnectCallback(EpollCallback cb)
			{	onConnectCallback_ = std::move(cb);	}
			void setMessageCallback(EpollCallback cb)
			{	onMessageCallback_ = std::move(cb);	}
			void setCloseCallback(EpollCallback cb)
			{	onCloseCallback_ = std::move(cb);	}

		private:
			void waiteEpollFd(); 
			void handleConnection();
			void handleMessage(int peerfd);
			
			const int epollfd_;
			const int listenfd_;
			bool isLooping_;

			typedef std::vector<struct epoll_event> EventList;
			EventList events_;

			typedef std::map<int, TcpConnectionPtr> ConnectionList;
			ConnectionList lists_;
			
			EpollCallback onConnectCallback_;
			EpollCallback onMessageCallback_;
			EpollCallback onCloseCallback_;
	};

}//end of namespace


#endif
