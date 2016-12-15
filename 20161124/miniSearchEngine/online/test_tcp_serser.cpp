

#include "TcpServer.h"
#include "Threadpool.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <string>
#include <functional>
using std::string;
using std::bind;

using namespace zx;

class MyServer
{
public:
	MyServer(const string & ip, 
			 unsigned short port, 
			 size_t threadNum, 
			 size_t bufSize);

	void start();

	void onConnection(const TcpConnectionPtr & conn)
	{
		printf("%s\n", conn->toString().c_str());
		conn->send("hello, welcome to Chat Server.\r\n");
	}

	void onMessage(const TcpConnectionPtr & conn)
	{
		std::string s(conn->receive());
		printf("from client: %s\n", s.c_str());

		_threadpool.addTask(std::bind(&MyServer::doTaskThread,
							this, conn, s));
	}

	void onClose(const TcpConnectionPtr & conn)
	{
		printf("%s close\n", conn->toString().c_str());
	}

	void doTaskThread(const TcpConnectionPtr & conn, const string & msg)
	{
		//string ret = doQuery(msg);
		conn->sendInLoop(msg);
	}
private:
	TcpServer _tcpServer;
	Threadpool _threadpool;
};


MyServer::MyServer(const string & ip, 
			 unsigned short port, 
			 size_t threadNum, 
			 size_t bufSize)
: _tcpServer(ip, port)
, _threadpool(threadNum, bufSize)
{
	using namespace std::placeholders;
	_tcpServer.setConnectionCallback(
			std::bind(&MyServer::onConnection, this, _1));
	_tcpServer.setMessageCallback(
			bind(&MyServer::onMessage, this, _1));
	_tcpServer.setCloseCallback(
			bind(&MyServer::onClose, this, _1));
}

void MyServer::start()
{
	_threadpool.start();
	_tcpServer.start();
}

int main(void)
{
	MyServer mySerever("192.168.49.133", 9999, 4, 10);
	mySerever.start();

	return 0;
}
