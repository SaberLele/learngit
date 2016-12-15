#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include"unistd.h"
#include"sys/types.h"
#include"sys/socket.h"
#include"arpa/inet.h"
#include"netinet/in.h"
#include"errno.h"

int main()
{
	int fd=socket(PF_INET,SOCK_STREAM,0);
	struct sockaddr_in addr={AF_INET,htons(9999),inet_addr("192.168.175.128")};
	connect(fd,(struct sockaddr *)&addr,sizeof(addr));
	char sen[1024];
	while(1)
	{
	
		memset(sen,0,sizeof(sen));
		fgets(sen,sizeof(sen),stdin);
		write(fd,sen, sizeof(sen));
		int nread = read(fd,sen, sizeof(sen));
		printf("get:%d bytes,receive:%s", nread, sen);
	}
	
}
