/*
MT2019114
Receive program one way communication using fifo.
*/

#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>

int main(void){
   
   char buf[100];
   int fd = open("fifo1",O_RDONLY);       
   read(fd,&buf,sizeof(buf));
   printf("message: %s\n",buf);
   close(fd);
   return 0;

}
