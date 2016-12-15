#include "ftp.h"

void send_order(int sfd,char* p)
{
	data d;
	memset(&d,0,sizeof(d));
	d.len=strlen(p);
	strcpy(d.buf,p);
	send_n(sfd,(char*)&d,d.len+4);
}

void recv_order(int sfd,char* p)
{
	int len;
	recv_n(sfd,(char*)&len,4);
	if(len>0)
	{
		recv(sfd,p,len,0);
	}
}

//ls函数

void dir_ls(char *s,data d,int sfd)
{
	memset(&d,0,sizeof(d));
	
	DIR* dir;
	chdir(s);
	dir=opendir(s);
	if(NULL==dir)
	{
		perror("opendir");
		exit(-1);
	}else
	{
		int ret;
		int i,j,k;
		struct stat buf;
		struct dirent* p;
		char str[11];
		while((p=readdir(dir)))
		{
			printf("%s\n",p->d_name);
			ret=stat(p->d_name,&buf);
			printf("ret=%d\n",ret);
			if(ret!=0)
			{
				perror("stat");
				exit(-1);
			}else
			{
				strcpy(str, "----------");
				if(S_ISDIR(buf.st_mode))
				{
					str[0]='d';
				}
				if(S_ISCHR(buf.st_mode))
				{
					str[0]='c';
				}
				if(S_ISBLK(buf.st_mode))
				{
					str[0]='b';
				}
				for(i=1,j=2,k=3;i<8;i=i+3,j=j+3,k=k+3)
				{
					if(buf.st_mode)
					{
						str[i]='r';
						str[j]='w';
						str[k]='x';
					}
				}
				sprintf(d.buf,"%s %2d %5s %5s %10ld %.9s %s\n",str,buf.st_nlink,getpwuid(buf.st_uid)->pw_name,getgrgid(buf.st_gid)->gr_name,buf.st_size,ctime(&buf.st_mtime)+4,p->d_name);
				printf("%s\n",d.buf);
				d.len=strlen(d.buf);
				send_n(sfd,(char*)&d,d.len+4);
			}

		}
		d.len=0;
		send_n(sfd,(char*)&d,4);
		closedir(dir);
	}
}


//删除文件函数
void rm_dir(int sfd,char* s)
{
	char next_s[100]={0};
	DIR *dir;
	
	dir=opendir(s);
	printf("s=%s\n",s);
	if(dir==NULL)
	{
		unlink(s);
	}else
	{
		struct dirent* p;
		while((p=readdir(dir)))
		{
			if(strcmp(p->d_name,".")==0||strcmp(p->d_name,"..")==0)
			{
				continue;
			}
			if(p->d_type==DT_DIR)
			{
				sprintf(next_s,"%s/%s",s,p->d_name);
				rm_dir(sfd,next_s);
			}
			else
			{
				sprintf(next_s,"%s/%s",s,p->d_name);
				if(unlink(next_s)<0)
				{
					printf("unlink error\n");
					return;
				}else
				{
					printf("unlink success\n");
				}
			}
		}
	}
	remove(s);
	printf("删除完成\n");
	send(sfd,"unlink success!",15,0);
	closedir(dir);
}

//账号密码验证
void get_salt(char *salt,char *passwd)
{
	int i,j;
	for(i=0,j=0;passwd[i] && j != 3;++i)
	{
		if(passwd[i] == '$')
			++j;
	}
	strncpy(salt,passwd,i-1);
}

int match(char* name,char* passwd)
{
	seteuid(0);
	struct spwd *sp;
	char salt[512]={0};

	sp=getspnam(name);
	get_salt(salt,sp->sp_pwdp);

	if(strcmp(sp->sp_pwdp,(char*)crypt(passwd,salt))==0)
	{
		printf("验证OK\n");
		seteuid(1000);
		return 1;
	}
	else
	{
		printf("验证file\n");
		return 0;
	}
}
