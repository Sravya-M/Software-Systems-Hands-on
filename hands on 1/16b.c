/* MT2019114
Mandatory locking: read lock
*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
	struct flock rlock;

	int fd=open("test.txt",O_RDONLY,0744);

	rlock.l_type=F_RDLCK;
	rlock.l_whence=SEEK_SET;
	rlock.l_start=0;
	rlock.l_len=20;
	rlock.l_pid=getpid();

	fcntl(fd,F_SETLKW,&rlock);

	char c[50];
	read(fd,&c,50);
	printf("%s",c);

	getchar();

	rlock.l_type=F_UNLCK;
	fcntl(fd,F_SETLKW,&rlock);
	
	return 0;	
}
