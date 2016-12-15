#include "ftp.h"

void send_n(int sfd,char* p,int len)     //循环发送直到数据量一致
{
	int total=0;
	int ret;
	while(total<len)
	{
		ret=send(sfd,p+total,len-total,0);
		total+=ret;
	}
}

void recv_n(int sfd,char* p,int len)
{
	int total=0;
	int ret;
	while(total<len)
	{
		ret=recv(sfd,p+total,len-total,0);
		total+=ret;
	}
}
