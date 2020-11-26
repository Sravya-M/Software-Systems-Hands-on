/*
MT2019114
ticket reservation example using semaphore to protect multiple pseudo resources ( may be two) using counting semaphore.
*/

#include<sys/ipc.h>
#include<sys/sem.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
#include<stdlib.h>

struct{
	int tno;
}db;

int main (void){
	int semkeyb,semidb,ret;
	fd_set rfd;
	struct timeval t;

	
	FD_ZERO(&rfd);
	FD_SET(0,&rfd);

	int fd = open("database",O_RDWR);
	read(fd,&db,sizeof(db));	
	printf("Current quantity of tickets booked : %d \n",db.tno);

	semkeyb = ftok(".",'c');

    	struct sembuf bufb = {0,-1,0};
	semidb = semget(semkeyb,1,0);

    	printf("Before entering into the critical section...\n");

    	semop(semidb,&bufb,1);
    	printf("Inside the critical section...\n");		
	db.tno++;
	lseek(fd,0,SEEK_SET);
	write(fd,&db,sizeof(db));
	close(fd);
			
	t.tv_sec = 10;
	t.tv_usec = 0;
	ret = select(1,&rfd,NULL,NULL,&t);
	
	if (ret){
		printf("Ticket is booked\n");
	}
	else{
		printf("Ticket is not booked\n");
		fd = open("database",O_RDWR);
		read(fd,&db,sizeof(db));
		db.tno--;
		lseek(fd,0,SEEK_SET);
		write(fd,&db,sizeof(db));
		close(fd);
		bufb.sem_op = 1;
    		semop(semidb,&bufb,1);
    	}	
	return 0;
}
