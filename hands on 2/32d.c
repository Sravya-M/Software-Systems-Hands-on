/*
MT2019114
remove the created semaphore.
*/

#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/sem.h>
#include<stdio.h>


int main(void){

    int semkeyc, semidc,semkeyb, semidb;
    semkeyc = ftok(".",'c');
    semkeyb = ftok(".",'b');
    semidc = semget (semkeyc,1,0);
    semidb = semget (semkeyb,1,0);
    semctl(semidc,0,IPC_RMID,0);
    semctl(semidb,0,IPC_RMID,0);
    return 0;
}
