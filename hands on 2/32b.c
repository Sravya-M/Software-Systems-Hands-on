/*
MT2019114
ticket reservation example using semaphore to protect shared memory from concurrent write access.
*/

#include<sys/ipc.h>
#include<sys/sem.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main (void){
	int semkeyb,semidb;
	struct{
		int tno;
	}db;
	
	int fd = open("database",O_RDWR);
	read(fd,&db,sizeof(db));	
	printf("Current quantity of tickets booked : %d \n",db.tno);

	semkeyb = ftok(".",'b');

    	struct sembuf bufb = {0,-1,0};
	semidb = semget(semkeyb,1,0);

    	printf("Before entering into the critical section...\n");

    	semop(semidb,&bufb,1);
    	printf("Inside the critical section...\n");		
	db.tno++;
	lseek(fd,0,SEEK_SET);
	write(fd,&db,sizeof(db));
	printf("Enter to unlock");
	getchar();
	
	bufb.sem_op = 1;
    	semop(semidb,&bufb,1);	
	printf("Ticket is booked\n");

	close(fd);
	
	return 0;
}
