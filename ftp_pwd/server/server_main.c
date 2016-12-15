#include "ftp.h"

int main(int argc,char* argv[])
{
	if(3!=argc)
	{
		printf("port pronum\n");    //端口和进程数
		return -1;
	}
	//申请pchild空间
	int num=atoi(argv[2]);
	short port=atoi(argv[1]);
	pchild p=(pchild)calloc(num,sizeof(child));
	//创建子进程
	make_child(p,num);

	int sfd=socket(AF_INET,SOCK_STREAM,0);
	if(-1==sfd)
	{
		perror("socket");
		return -1;
	}
	struct sockaddr_in ser;
	memset(&ser,0,sizeof(ser));
	ser.sin_family=AF_INET;
	ser.sin_port=htons(port);
	ser.sin_addr.s_addr=INADDR_ANY;
	int ret;
	char buf[100]={0};
	ret=bind(sfd,(struct sockaddr*)&ser,sizeof(ser));
	if(-1==ret)
	{
		perror("bind");
		return -1;
	}
	listen(sfd,num);

	//注册
	int epfd=epoll_create(1);
	struct epoll_event event,*evs;
	evs=(struct epoll_event*)calloc(num+1,sizeof(event));
	event.events=EPOLLIN;
	event.data.fd=sfd;
	epoll_ctl(epfd,EPOLL_CTL_ADD,sfd,&event);
	int i;
	for(i=0;i<num;i++)
	{
		event.events=EPOLLIN;
		event.data.fd=p[i].fdw;
		epoll_ctl(epfd,EPOLL_CTL_ADD,p[i].fdw,&event);
	}

	int new_fd;
	int j;
	char flag;
	while(1)
	{
		memset(evs,0,sizeof((num+1)*sizeof(event)));
		ret=epoll_wait(epfd,evs,num+1,-1);
		if(ret>0)
		{
			for(i=0;i<ret;i++)
			{
				if(evs[i].events==EPOLLIN && evs[i].data.fd==sfd)
				{
					new_fd=accept(sfd,NULL,NULL);   //不保存客户端
					//日志记录客户端连接时间
					seteuid(1000);
					int fd=open("log",O_CREAT|O_RDWR|O_APPEND,0777);
					time_t t;
					time(&t);
					sprintf(buf,"%s%s%s","客户端连接","    ",ctime(&t));
					write(fd,buf,strlen(buf));
					seteuid(0);

					if(-1==new_fd)
					{
						perror("accept");
						return -1;
					}
					for(j=0;j<num;j++)
					{
						if(p[j].busy==0)
						{
							break;
						}
					}
					send_fd(p[j].fdw,new_fd);
					close(new_fd);
					p[j].busy=1;
					printf("the child is busy\n");
				}
				for(j=0;j<num;j++)
				{
					if(p[j].fdw==evs[j].data.fd)
					{
						read(p[j].fdw,&flag,sizeof(flag));
						p[j].busy=0;
						printf("the child is not busy\n");
					}
				}
			}
		}
	}
}
