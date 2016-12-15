 ///
 /// @file    Socket.h
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-20 18:14:04
 ///

#ifndef __SOCKET_H__
#define __SOCKET_H__

#include "Noncopyable.h"
#include "InterAddress.h"

namespace zx
{
	
	class Socket
	:private Noncopyable
	{
		public:
			explicit Socket(int sockfd);
			~Socket();

			void ready(const InetAddress & inetAddr);
			
			int fd() const { return sockfd_; }
			void bindAddress(const InetAddress & addr);
			void listen();
			int accept();

			void shutdownWrite();
			
			void setTcpNoDelay(bool on);
			void setReuseAddr(bool on);
			void setReusePort(bool on);
			void setKeepAlive(bool on);

			static InetAddress getLocalAddr(int sockfd);
			static InetAddress getPeerAddr(int sockfd);

		private:
			const int sockfd_;
	};

}//end of namespace zx

#endif
