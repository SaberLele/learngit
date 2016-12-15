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
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>
#include <grp.h>
#include <pwd.h>
#include <shadow.h>
#include <errno.h>
//#define HOME "/home/saberle/"

typedef struct{
	pid_t pid;
	int fdw;
	short busy;       //0是非忙碌，1就是忙碌
}child,*pchild;

typedef struct{
	int len;
	char buf[1000];
}data;             //数据发送单元

void make_child(pchild,int);
void child_handle(int);
void send_fd(int,int);
void recv_fd(int,int*);
void send_n(int,char*,int);
void recv_n(int,char*,int);

void send_order(int,char*);
void recv_order(int,char*);

void dir_ls(char*,data,int);
void send_file(int,char*); 
void rm_dir(int,char*);

void get_salt(char*,char*);
int match(char*,char*);
