#include "ftp.h"

int main(int argc,char* argv[])
{
	if(3!=argc)
	{
		printf("IP,PORT\n");
		return -1;
	}

	int sfd=socket(AF_INET,SOCK_STREAM,0);
	struct sockaddr_in ser;
	memset(&ser,0,sizeof(ser));
	ser.sin_family=AF_INET;
	ser.sin_port=htons(atoi(argv[2]));
	ser.sin_addr.s_addr=inet_addr(argv[1]);

	int ret;
	ret=connect(sfd,(struct sockaddr*)&ser,sizeof(ser));
	if(-1==ret)
	{
		perror("bind");
		close(sfd);
		return -1;
	}

	char buf[1000]={0};
	data d;
	char tmp;
	int len;
	int fd;
	int i=2;
	char filename[100]={0};          //文件名字
	system("clear");
	printf("输入账号：\n");
	//输入账号密码
	for(;i>=0;i--)
	{
		memset(&d,0,sizeof(d));
		read(0,d.buf,sizeof(d.buf));
		d.len=strlen(d.buf)-1;
		send(sfd,&d,d.len+4,0);
		memset(&d,0,sizeof(d));
		printf("输入密码：\n");
		read(0,d.buf,sizeof(d.buf));
		d.len=strlen(d.buf)-1;
		send(sfd,&d,d.len+4,0);
		memset(&d,0,sizeof(d));
		recv(sfd,&tmp,1,0);
		if(tmp=='0')
		{
			printf("账号密码错误啦\n");
		}else
		{
			break;
		}
	}

	while(1)
	{
		printf("\n请输入命令:(pwd查看当前路径哦)\n");
		memset(&d,0,sizeof(d));
		ret=read(0,d.buf,sizeof(d.buf));
		if(ret>0)
		{
			system("clear");
			memset(buf,0,sizeof(buf));
			d.len=strlen(d.buf)-1;
			send(sfd,&d,d.len+4,0);       //客户端命令；
			if(!strcmp(d.buf,"pwd\n"))
			{
				recv(sfd,&tmp,1,0);
				if(tmp=='0')
				{
					printf("\t error order\n");
				}else
				{
					recv_pwd(sfd,buf);
					printf("\n");
					printf("\t当前目录为：%s\n",buf);
				}
			}
			else if(!strncmp(d.buf,"cd ",3))
			{
				recv(sfd,&tmp,1,0);
				if(tmp=='0')
				{
					printf("\n");
					printf("\t服务器目录无权操作或者文件错误，建议pwd查询当前目录\n");	
				}else
				{
					recv_pwd(sfd,buf);
					printf("\n");
					printf("\t当前目录为：%s\n",buf);
				}
			}
			else if(!strncmp(d.buf,"ls",2))
			{
				if(!strcmp(d.buf,"ls\n"))
				{
					while(1)
					{
						memset(buf,0,sizeof(buf));
						recv_n(sfd,(char*)&len,4);
						if(len>0)
						{
							recv_n(sfd,buf,len);
							printf("\n");
							printf("\t%s\n",buf);
						}else
						{
							break;
						}
					}
				}
				else if(!strncmp(d.buf,"ls ",3))
				{
					recv(sfd,&tmp,1,0);
					if(tmp=='0')
					{
						printf("\n");
						printf("\t服务器目录无权操作或者文件错误，建议pwd查询当前目录\n");	
					}else
					{
						while(1)
						{
							memset(buf,0,sizeof(buf));
							recv_n(sfd,(char*)&len,4);
							if(len>0)
							{
								recv_n(sfd,buf,len);
								printf("\n");
								printf("\t%s\n",buf);
							}else
							{
								break;
							}
						}
					}

				}
			}
			else if(!strncmp(d.buf,"puts ",5))
			{
				strcpy(filename,d.buf+5);
				filename[strlen(filename)-1]='\0';
				printf("\tfilename=%s\n",filename);
				if(filename==NULL)
				{
					printf("文件不存在\n");
				}
				if(access(filename,F_OK)==0)
				{
					printf("\t开始上传咯!\n");
					send_file(sfd,filename);	
					printf("\t上传成功鸟!\n");
				}else
				{
					printf("\t你就没有这个文件!\n");
				}
			}
			else if(!strncmp(d.buf,"gets ",5))
			{
				recv(sfd,&tmp,1,0);
				if(tmp=='1')
				{
					struct stat s;
					long int t=0;
					recv(sfd,&len,4,0);
					recv(sfd,buf,len,0);
					d.buf[strlen(d.buf)-1]='\0';
					int ret=stat(d.buf+5,&s);
					if(ret==0)
					{
						send(sfd,&s.st_size,4,0);
					}else
					{
						send(sfd,&t,4,0);
					}
					printf("\tfilename=%s开始下载\n",buf);
					fd=open(buf,O_RDWR|O_CREAT|O_APPEND,0666);
					if(-1==fd)
					{
						perror("open");
					}
					
					while(1)
					{
						memset(buf,0,sizeof(buf));
						recv_n(sfd,(char*)&len,4);
						if(len>0)
						{
							recv_n(sfd,buf,len);
							write(fd,buf,len);
						}else
						{
							printf("\t下载完成鸟\n");
							break;
						}
					}
				}
				if(tmp=='0')
				{
					printf("\n\t服务端没有你要的文件\n");
				}
			}
			else if(!strncmp(d.buf,"remove ",7))
			{
				recv(sfd,&tmp,1,0);
				if(tmp=='0')
				{
					printf("\n\t越权了，会删掉服务器目录的!\n");
				}
				else
				{
					printf("\n\t删除开始咯！\n");
					recv(sfd,buf,15,0);
					printf("\n\t%s\n",buf);
				}
			}
			else
			{
				printf("\n\t请原谅我做不出其他命令\n");
			}
		}else if(ret==EOF || ret<=0)
		{
			d.len=0;
			send(sfd,&d,d.len+4,0);
			break;
		}
	}
	close(sfd);
}
