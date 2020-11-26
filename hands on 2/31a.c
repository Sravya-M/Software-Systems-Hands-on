/*
MT2019114
creating binary semaphore and initializing value of semaphore
semget: will return semphore identifier
semctl: will define control operations. 1 = binary semphore, >1 couting semaphore
check initialized value using 'ipcs -s -i semid'
*/

#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/sem.h>
#include<stdio.h>

union semun{
   int val; // value for SETVAL
   struct semid_ds *buf; // buffer for IPC_STAT, IPC_SET
   unsigned short int *array; // array for GETALL, SETALL
 };

int main(void){

    union semun arg;
    int semkey, semid;
    semkey = ftok(".",'b');
    semid = semget (semkey,1,IPC_CREAT | 0744);
    arg.val = 1;
    /* 1 for binary else >1 for counting semaphore */
    semctl(semid,0,SETVAL,arg);
    return 0;

}
