#include "ftp.h"

void make_child(pchild p,int num)
{
	int fds[2];
	pid_t pid;
	int i;
	for(i=0;i<num;i++)
	{
		socketpair(AF_LOCAL,SOCK_STREAM,0,fds);
		pid=fork();
		if(0==pid)
		{
			close(fds[1]);
			//子进程操作函数
			child_handle(fds[0]);
		}
		close(fds[0]);
		//写入结构体
		p[i].pid=pid;
		p[i].fdw=fds[1];     
	}
}

void child_handle(int fdr)
{
	int sfd;     //父进程传递的描述符
	char flag='1';
	data d;
	char porder[100]={0};
	char buf[1000]={0};
	int len;
	int fd;
	int ret;
	int i;
	char name[50]={0};
	char passwd[50]={0};
	char filename[100]={0};   //下载文件名
	char HOME[100]={0};
	while(1)
	{
		recv_fd(fdr,&sfd);

		//接收账户名密码验证
		for(i=2;i>=0;i--)
		{
			recv(sfd,&len,4,0);
			recv(sfd,name,len,0);
			printf("name=%s\n",name);
			recv(sfd,&len,4,0);
			recv(sfd,passwd,len,0);
			printf("passwd=%s\n",passwd);
			ret=match(name,passwd);
			printf("ret=%d\n",ret);
			if(ret==0)
			{
				send(sfd,"0",1,0);
			}
			else
			{
				send(sfd,"1",1,0);
				sprintf(HOME,"%s%c%s","/home/saberle",'/',name);
				printf("buf=%s\n",HOME);
				mkdir(buf,0700);
				break;
			}
		}

		chdir(HOME);
		while(1)
		{
			memset(buf,0,sizeof(buf));
			memset(porder,0,sizeof(porder));
			memset(&d,0,sizeof(d));
			//recv_order(sfd,porder);
			ret=recv(sfd,&len,4,0);
			if(ret>0&&len>0)
			{
				ret=recv(sfd,porder,len,0);
				
				if(ret>0)
				{
					printf("porder=%s\n",porder);
					//记录命令操作时间，存日志
					seteuid(1000);
					int fd=open("/home/saberle/Documents/20161014/ftp_pwd/server/log",O_CREAT|O_RDWR|O_APPEND,0777);
					time_t t;
					time(&t);
					sprintf(buf,"%s%s%s",porder," 操作:     ",ctime(&t));
					write(fd,buf,strlen(buf));
					seteuid(0);

					if(!strcmp(porder,"pwd"))
					{
						strcpy(d.buf,getcwd(NULL,0));
						printf("pwd_d.buf=%s\n",d.buf);
						if(NULL==d.buf)
						{
							send(sfd,"0",1,0);
						}else
						{
							send(sfd,"1",1,0);	
							d.len=strlen(d.buf);
							send_n(sfd,(char*)&d,d.len+4);
						}
					}
					else if(!strncmp(porder,"cd ",3))
					{
						char *path=getcwd(NULL,0);
						sprintf(d.buf,"%s%s%s",getcwd(NULL,0),"/",porder+3);
						printf("d.buf=%s\n",d.buf);
						ret=chdir(d.buf);
						if(-1==ret)
						{
							perror("chdir");
							send(sfd,"0",1,0);
						}else
						{
							if(memcmp(getcwd(NULL,0),HOME,strlen(HOME)))
							{
								chdir(path);
								send(sfd,"0",1,0);
							}else
							{
								send(sfd,"1",1,0);
								printf("current path=%s\n",getcwd(NULL,0));
								memset(d.buf,0,sizeof(d.buf));
								strcpy(d.buf,getcwd(NULL,0));
								d.len=strlen(d.buf);
								send_n(sfd,(char*)&d,d.len+4);
							}
						}
					}
					else if(!strncmp(porder,"ls",2))
					{
						char *path=getcwd(NULL,0);
						printf("path=%s\n",path);
						if(!strcmp(porder,"ls"))
						{
							dir_ls(path,d,sfd);
						}
						else if(!strncmp(porder,"ls ",3))
						{
							ret=chdir(porder+3);					
							if(-1==ret)
							{
								perror("chdir");
								send(sfd,"0",1,0);
							}else
							{
								if(memcmp(getcwd(NULL,0),HOME,strlen(HOME)))
								{
									chdir(path);
									send(sfd,"0",1,0);
								}else
								{		
									send(sfd,"1",1,0);
									printf("current path=%s\n",getcwd(NULL,0));
									dir_ls(getcwd(NULL,0),d,sfd);
								}
							}
						}
					}
					else if(!strncmp(porder,"puts ",5))
					{
						recv(sfd,&len,4,0);
						recv(sfd,buf,len,0);
						printf("buf=%s\n",buf);
						fd=open(buf,O_RDWR|O_CREAT,0666);
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
								break;
							}
						}
					}
					else if(!strncmp(porder,"gets ",5))
					{
						strcpy(filename,porder+5);
						printf("filename=%s\n",filename);
						if(filename==NULL)
						{
							printf("文件不存在\n");
						}
						if(access(filename,F_OK)==0)
						{
							send(sfd,"1",1,0);
							send_file(sfd,filename);
							printf("已下载成功\n");
						}else
						{
							send(sfd,"0",1,0);
							printf("没有我怎么下载给你\n");
						}
					}
					else if(!strncmp(porder,"remove ",7))
					{
						if(!strcmp(getcwd(NULL,0),HOME)&&!strncmp("..",porder+7,2))
						{
							send(sfd,"0",1,0);
							printf("不能操作根目录\n");
						}
						else
						{
							char *path=getcwd(NULL,0);
							strcpy(buf,porder+7);
							printf("buf=%s\n",buf);
							int i=strlen(buf)-1;
							printf("i=%d\n",i);
							char path_last[100]={0};
							for(;i>=0;i--)
							{
								if(buf[i]=='/'&&i!=strlen(buf)-1)
								{
									strcpy(path_last,&buf[i+1]);
									printf("i=%d\n",i);
									buf[i+1]='\0';
									break;
								}
							}
							printf("buf=%s\n",buf);
							if(!strcmp(buf,porder+7))
							{
								chdir(porder+7);
								if(!strcmp(getcwd(NULL,0),HOME)&&!strncmp("..",porder+7,2))
								{
									send(sfd,"0",1,0);
									printf("不能操作根目录\n");
								}else
								{
									send(sfd,"1",1,0);
									printf("current path=%s\n",porder+7);
									rm_dir(sfd,porder+7);
								}
							}else
							{
								chdir(porder+7);
								if(!strcmp(getcwd(NULL,0),HOME)||strlen(getcwd(NULL,0))<strlen(HOME))
								{
									chdir(path);
									send(sfd,"0",1,0);
								}else
								{
									printf("现在地址=%s\n",getcwd(NULL,0));
									send(sfd,"1",1,0);
									printf("current path=%s\n",path_last);
									rm_dir(sfd,path_last);
								}
							}
						}
					}
				}else
				{
					write(fdr,&flag,1);
					break;
				}
			}
			else if(len==0)
			{
				write(fdr,&flag,1);
				break;
			}
		}
	}
}
