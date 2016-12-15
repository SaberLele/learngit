 ///
 /// @file    SocketIO.h
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-21 04:35:08
 ///

#ifndef __SOCKETIO_H__
#define __SOCKETIO_H__

#include "Noncopyable.h"
#include <sys/types.h>

//处理数据发送接收
namespace zx
{
	class SocketIO
	:Noncopyable
	{
		public:
			explicit SocketIO(int sockfd)
			:sockfd_(sockfd)
			{
			}
			
			ssize_t readn(char *buf, size_t count);
			ssize_t writen(const char *buf, size_t count);
			ssize_t readline(char *usrbuf, size_t maxlen);

		private:
			ssize_t recv_peek(char * buf, size_t len);

			const int sockfd_;
	};
}//end of namespace zx

#endif
