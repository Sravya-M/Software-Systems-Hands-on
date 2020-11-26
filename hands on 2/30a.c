/*
MT2019114
sending data through shared memeory
shmget: used to create a shared memory segment.
shmat: used to attach the created shared memory segment onto a process address space. A pointer is returned on the successful execution of the system call and the process can read or write to the segment using the pointer. 
*/

#include<stdio.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/shm.h>

int main(void) {

  int shmkey, shmid;
  char *data;
  
  shmkey = ftok(".",'r');
  shmid = shmget(shmkey,1024,IPC_CREAT|0744);
  printf("Shared memory I'd: %d\n",shmid);
  data = shmat(shmid,0,0);
  printf("Enter the text: ");
  scanf(" %[^\n]",data); // as its already pointer no need of &  and scanned value goes to pointed data.
  return 0; 

}
