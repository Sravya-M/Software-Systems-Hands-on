/*
MT2019114
database to store ticket number
*/
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
#include<stdlib.h>


int main (void){
	int fd = open("database",O_CREAT|O_RDWR,0744);
	struct{
		int tno;
		}db;
	
	db.tno = 0;
	write(fd,&db,sizeof(db));
	close(fd);
	fd = open("database",O_RDONLY);
	read(fd,&db,sizeof(db));
	printf("Total tickets booked : %d\n",db.tno);
	close(fd);
	return 0;
}
