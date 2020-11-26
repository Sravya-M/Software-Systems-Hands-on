/*
MT2019114
Receive program one way communication using fifo.
using select to wait for particular time if data is not given within that time it terminates.
*/

#include<sys/types.h>
#include<sys/stat.h>
#include<time.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>

int main(void){

	char buf[100];
	int fd = open("fifo1",O_RDONLY); 
	
	fd_set rfd;
	struct timeval t;
	int ret;
	
	FD_ZERO(&rfd);
	FD_SET(fd,&rfd);
	
	t.tv_sec = 10;
	t.tv_usec = 0;

	ret = select(fd+1,&rfd,NULL,NULL,&t);
	
	if (ret){
		read(fd,&buf,sizeof(buf));
    		printf("message: %s\n",buf);
	}
	else
		printf("No Data within 10s\n");
    
    close(fd);
   return 0;

}
