#include <arpa/inet.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/epoll.h>
#include <sys/select.h>
#include <sys/wait.h>
#include <sys/uio.h>
#include <signal.h>

typedef struct{
	pid_t pid;
	short busy;
	int fdw;
}child,*pchild;

typedef struct{
	int len;
	char buf[1000];
}data;

void make_child(pchild,int);
void child_handle(int);
void recv_fd(int,int*);
void send_fd(int,int);
void send_file(int,char*);
void send_n(int,char*,int);
void recv_n(int,char*,int);

void recv_pwd(int,char*);
