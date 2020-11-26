/*
MT2019114
Send program 2 way communication using fifo
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(void){
   
   int fd0, fd1;
   char buf0[50],buf1[50];
   fd0=open("fifo0",O_WRONLY);
   fd1=open("fifo1",O_RDONLY); 
   printf("Enter the message: ");
   scanf(" %[^\n]",buf0);
   write(fd0,&buf0,sizeof(buf0)); // writing to fifo0 write only mode
   read(fd1,&buf1,sizeof(buf1)); // reading from fifo1 readonly mode 
   printf("message from fifo1: %s\n",buf1);
   return 0;

}
