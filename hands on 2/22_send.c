/*
MT2019114
Send program one way communication using fifo.
*/

#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>

int main(void){
   
   char buf[100];
   int fd = open("fifo1",O_RDWR);
   printf("Enter the message: \n");
   scanf(" %[^\n]",buf);    
   write(fd,&buf,sizeof(buf));
   close(fd);
   return 0;

}
