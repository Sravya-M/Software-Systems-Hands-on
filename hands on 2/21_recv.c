/*
MT2019114
Receive program 2 way communication using fifo
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(void){

   int fd0, fd1;
   char buf0[50],buf1[50];
   fd0=open("fifo0",O_RDONLY); // read from the pipe0
   fd1=open("fifo1",O_WRONLY); // write to pipe1
   read(fd0,&buf0,sizeof(buf0)); 
   printf("Message from fifo0: %s\n",buf0);
   printf("Enter the message: ");	
   scanf(" %[^\n]",buf1);
   write(fd1,&buf1,sizeof(buf1));
   return 0;	
}
