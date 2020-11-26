/* MT2019114
Mandatory locking: write lock
*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
	struct flock rlock;

	int fd=open("test.txt",O_WRONLY,0744);
	rlock.l_type=F_WRLCK;
	rlock.l_whence=SEEK_SET;
	rlock.l_start=0;
	rlock.l_len=0;
	rlock.l_pid=getpid();

	fcntl(fd,F_SETLKW,&rlock);
	lseek(fd,0,SEEK_END);

	write(fd,"write lock",sizeof("write lock")-1);

	getchar();

	rlock.l_type=F_UNLCK;
	fcntl(fd,F_SETLKW,&rlock);
	
	return 0;	
}
