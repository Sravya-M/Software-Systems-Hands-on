#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

// for application purpose, i.e., incrementing the ticket number and updating it

int main()
{
	struct ticket
	{
	int tno;
	}t;

	int fd=open("ticket.txt",O_RDWR,0744);

// set the locking parameters
	struct flock rlock;
	rlock.l_type=F_WRLCK;
	rlock.l_whence=SEEK_SET;
	rlock.l_start=0;
	rlock.l_len=0;
	rlock.l_pid=getpid();

	read(fd,&t,sizeof(t));

// locking
	fcntl(fd,F_SETLKW,&rlock);
// CS - Critical Section
	t.tno++;

	lseek(fd,0,SEEK_SET);
	write(fd,&t,sizeof(t));
// CS

// unlocking
	rlock.l_type=F_UNLCK;
	fcntl(fd,F_SETLKW,&rlock);

	
	printf("%d\n",t.tno);
	close(fd);
	
	return 0;	
}
