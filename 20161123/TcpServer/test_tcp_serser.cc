#include "TcpServer.h"
#include "Threadpool.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string>
#include <functional>

using namespace zx;

class Myserver
{
	public:
		Myserver(const std::string & ip,
				 unsigned short port,
				 size_t threadnum,
				 size_t bufSize);
		void start();

		void onConnection(const TcpConnectionPtr &conn)
		{
			printf("%s\n", conn->toString().c_str());
			conn->send("hello, welcome to Chat Server.\r\n");
		}

		void onMessage(const TcpConnectionPtr & conn)
		{
			std::string s(conn->receive());
			printf("from client: %s\n", s.c_str());

			_threadpool.addTask(std::bind(&Myserver::doTaskThread,
								this,conn,s));
		}

		void onClose(const TcpConnectionPtr & conn)
		{
			printf("%s close\n", conn->toString().c_str());
		}

		void doTaskThread(const TcpConnectionPtr & conn, const std::string & msg)
		{
			//string ret = doQuery(msg);
			//conn->sendInloop(msg);
			conn->send(msg);
		}
	private:
		TcpServer _tcpServer;
		Threadpool _threadpool;
};

Myserver::Myserver(const std::string & ip,
			unsigned short port,
			size_t threadnum,
			size_t bufSize)
:_tcpServer(ip,port)
,_threadpool(threadnum,bufSize)
{
	using namespace std::placeholders;
	_tcpServer.setConnectCallback(std::bind(&Myserver::onConnection,this, _1));
	_tcpServer.setMessageCallback(std::bind(&Myserver::onMessage,this, _1));
	_tcpServer.setCloseCallback(std::bind(&Myserver::onClose,this, _1));
}

void Myserver::start()
{
	_threadpool.start();
	_tcpServer.start();
}

#if 0
void onConnection(const zx::TcpConnectionPtr &conn)
{
    printf("%s\n", conn->toString().c_str());
    conn->send("hello, welcome to Chat Server.\r\n");
}

void onMessage(const zx::TcpConnectionPtr &conn)
{
    std::string s(conn->receive());
	printf("from client: %s\n", s.c_str());
   // conn->sendInloop(s);
   // conn->send(s);
}

void onClose(const zx::TcpConnectionPtr &conn)
{
    printf("%s close\n", conn->toString().c_str());
}

int main()
{
	zx::TcpServer server("192.168.1.97", 9999);
    server.setConnectCallback(&onConnection);
    server.setMessageCallback(&onMessage);
    server.setCloseCallback(&onClose);

    server.start();

    return 0;
}
#endif

int main()
{
	Myserver myserver("192.168.1.97",9999,4,10);
	myserver.start();

	return 0;
}
