#include "ftp.h"


void recv_pwd(int sfd,char* buf)
{
	int len;
	memset(buf,0,sizeof(buf));
	recv_n(sfd,(char*)&len,4);
	if(len>0)
	{
		recv_n(sfd,buf,len);
	}
}
