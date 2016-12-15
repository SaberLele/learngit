 ///
 /// @file    TcpConnection.h
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-21 05:24:30
 ///

#ifndef __TCPCONNECTION_H__
#define __TCPCONNECTION_H__

#include "Noncopyable.h"
#include "Socket.h"
#include "SocketIO.h"
#include <memory>
#include <functional>

namespace zx
{

	class TcpConnection;
	typedef std::shared_ptr<TcpConnection> TcpConnectionPtr;

	class TcpConnection
	:Noncopyable
	,public std::enable_shared_from_this<TcpConnection>
	{

		public:

			typedef std::function<void(const TcpConnectionPtr &)> TcpConnectionCallback;

			explicit TcpConnection(int sockfd);
			~TcpConnection();

			void setConnectCallback(TcpConnectionCallback cb)
			{
				onConnectCallback_ = std::move(cb);
			}
			void setMessageCallback(TcpConnectionCallback cb)
			{
				onMessageCallback_ = std::move(cb);
			}
			void setCloseCallback(TcpConnectionCallback cb)
			{
				onCloseCallback_ = std::move(cb);
			}

			void handleConnectCallback();
			void handleMessageCallback();
			void handleCloseCallback();

			void shutdown()
			{
				sockfd_.shutdownWrite();
				isShutdownWrite_=true;
			}

			ssize_t readn(char *buf, size_t count);
			ssize_t writen(const char * buf, size_t count);
			ssize_t readLine(char *usrbuf, size_t maxlen);

			std::string receive();
			void send(const std::string & s);

			const InetAddress &getLocalAddr() const
			{	return localAddr_;	}
			const InetAddress &getPeerAddr() const
			{	return peerAddr_;	}

			std::string toString() const;

		private:
			Socket sockfd_;
			SocketIO sockIO_;
			const InetAddress localAddr_;
			const InetAddress peerAddr_;
			bool isShutdownWrite_;

			TcpConnectionCallback onConnectCallback_;
			TcpConnectionCallback onMessageCallback_;
			TcpConnectionCallback onCloseCallback_;
	};

}//end of namespace zx

#endif
