#include "ftp.h"

void send_file(int new_fd,char* filename)
{
	data d;
	long int file_len;
	memset(&d,0,sizeof(d));
	d.len=strlen(filename);
	printf("d.len=%d\n",d.len);
	strcpy(d.buf,filename);
	send(new_fd,&d,d.len+4,0);
	recv(new_fd,&file_len,4,0);
	int fd=open(filename,O_RDONLY);
	if(-1==fd)
	{
		perror("open");
		return;
	}
	lseek(fd,file_len,SEEK_SET);
	printf("file_len=%ld\n",file_len);

	while(memset(&d,0,sizeof(d)),(d.len=read(fd,&d.buf,sizeof(d.buf)))>0)
	{
		send_n(new_fd,(char*)&d,d.len+4);
	}

	d.len=0;
	send_n(new_fd,(char*)&d,4);
}

