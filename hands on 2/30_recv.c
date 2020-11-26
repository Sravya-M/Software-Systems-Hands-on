/*
MT2019114
receiving data from shared memeory
shmget: used to create a shared memory segment. (we pass 0 as last argument as wea are reading from shared memory)
shmat: used to attach the created shared memory segment onto a process address space. A pointer is returned on the successful execution of the system call and the process can read or write to the segment using the pointer. 
*/

#include<stdio.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/shm.h>

int main(void) {
   int shmkey,shmid;
   char *data; // pointer
   shmkey = ftok(".",'r');
   shmid = shmget(shmkey,1024,0);
   data = shmat(shmid,0,0);
   printf("Text from shared memory: %s\n",data);
   return 0;
}
