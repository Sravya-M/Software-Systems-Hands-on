/*
MT2019114
sending data through shared memeory
shmget: used to create a shared memory segment.
shmat: used to attach the created shared memory segment onto a process address space. A pointer is returned on the successful execution of the system call and the process can read or write to the segment using the pointer. 
shmctl: This permanently removes it. 
*/

#include<stdio.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/shm.h>

int main(void) {

  int shmkey, shmid;
  char *data;
  
  shmkey = ftok(".",'r');
  shmid = shmget(shmkey,1024,0);
  printf("Shared memory before removing I'd: %d\n",shmid);
  shmctl(shmid,IPC_RMID,NULL);
  shmid = shmget(shmkey,1024,0);
  printf("Shared memory after removing I'd: %d\n",shmid);
  return 0; 

}
