 ///
 /// @file    SocketIO.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-21 04:42:52
 ///

#include "SocketIO.h"
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>

namespace zx
{

	ssize_t SocketIO::readn(char *buf, size_t count)
	{
		size_t nleft = count;   //剩余字节数
		ssize_t nread;          //返回值
		char * bufp = (char*) buf;  //缓冲区偏移量

		while(nleft>0)
		{
			nread = ::read(sockfd_, bufp, nleft);
			if(nread == -1)
			{
				if(errno == EINTR)
					continue;
				return -1;
			}
			else if(nread == 0)
				break;

			nleft -= nread;
			bufp += nread;
		}

		return (count - nleft);
	}

	ssize_t SocketIO::writen(const char *buf,size_t count)
	{
		size_t nleft = count;
		ssize_t nwrite;
		const char *bufp = buf;

		while(nleft > 0)
		{
			nwrite = ::write(sockfd_, bufp, nleft);
			if(nwrite <= 0)
			{
				if(nwrite == -1 && errno == EINTR)
					continue;
				return -1;
			}

			nleft -= nwrite;
			bufp += nwrite;
		}

		return count;
	}

	//预览内核缓冲区的数据
	//如果flag设置为0，此时recv读取tcp buffer（内核缓冲区）中的数据到buf中，
	//并从tcp buffer中移除已读取数据；
	//如果设置为MSG_PEEK则仅仅是读取，并不把已读取的数据从内核缓冲区中移除，
	//再次调用则可以读到刚刚的数据；——其实就是可以先预览到缓冲区数据，
	//查看自己所需数据的位置，然后再指针偏移recv接收（数据不会删除）；
	ssize_t SocketIO::recv_peek(char* buf, size_t len)
	{
		int nread;
		do
		{
			nread = ::recv(sockfd_, buf, len, MSG_PEEK);
		}while(nread == -1 && errno == EINTR);

		return nread;
	}

	ssize_t SocketIO::readline(char *usrbuf, size_t maxlen)
	{
		size_t nleft = maxlen -1;
		char *bufp = usrbuf;   //缓冲区的位置
		size_t total = 0;      //读取字节数

		ssize_t nread;
		while(nleft > 0)
		{
			//预读取
			nread = recv_peek(bufp, nleft);
			if(nread <= 0)
				return nread;

			//检查\n
			int i;
			for(i=0; i<nread; ++i)
			{
				if(bufp[i] == '\n')
				{
					size_t nsize = i+1;
					if(readn(bufp, nsize) != static_cast<ssize_t>(nsize))
						return -1;
					bufp += nsize;
					total += nsize;
					*bufp = 0;
					return total;
				}
			}
			if(readn(bufp, nread) != nread)
				return -1;
			bufp += nread;
			total += nread;
			nleft -= nread;
		}
		*bufp = 0;
		return maxlen - 1;
	}

}//end of namespace zx

