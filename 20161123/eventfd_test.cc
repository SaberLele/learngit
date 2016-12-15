 ///
 /// @file    eventfd_test.cc
 /// @author  SaberLele(le13424274771@gmail.com)
 /// @date    2016-11-22 23:15:32
 ///

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/eventfd.h>
#include <iostream>
using std::cout;
using std::endl;

//do while(0)成独立块，起保护作用，以免使用宏上下文对该语句块影响；
#define handle_error(msg)\
	do{\
		perror(msg);\
		exit(EXIT_FAILURE);\
	}while(0)

int main(int argc, char* argv[])
{
	if(argc < 2)
	{
		fprintf(stderr, "Usage %s <num> ...\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	int evfd = eventfd(10,EFD_NONBLOCK);
	if(evfd == -1)
	{
		handle_error("eventfd");
	}

	uint64_t u;
	switch(fork())
	{
		case 0:
			{
				for(int i=1; i<argc; ++i)
				{
					printf("Child writing %s to evfd\n", argv[i]);
					u = strtoull(argv[i],NULL,0);
					int ret = write(evfd, &u, sizeof(u));
					if(ret != sizeof(u))
					{
						handle_error("write");
					}
					sleep(1);
				}
				printf("Child has completed write");
				exit(EXIT_FAILURE);
			}
		case 1:
			{
				handle_error("fork");
				exit(0);
			}
		default:
			{
				printf("Parent about to read!\n");
				for(int idx=0; idx != 4; ++idx)
				{
					sleep(1);
					int ret = read(evfd, &u, sizeof(u));
					if(ret!=sizeof(u))
					{
						handle_error("read");
					}
					printf("Parent read %llu from evfd\n",(unsigned long long) u);
				}
				exit(EXIT_FAILURE);
			}
	}
}


