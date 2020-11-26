/*Author: Sravya. M (MT2019114)
fcntl(fd,F_DUPFD,0);   // what is the role of 0 here?
fcntl(fd,F_GETFD);
fcntl(fd,F_SETFD);
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

int main()
{
	int fd=open("11test.txt",O_RDWR | O_APPEND,0744);
	int fd3=fcntl(fd,F_DUPFD,0);

	printf("%d ",fd);  		// 11test.txt
	printf("%d ",fd3);		// 11test.txt using fcntl

// writing into different file descriptors (which are pointing to the same file
	write(fd, "base\n", strlen("base\n"));
	write(fd3, "fcntl\n", strlen("fcntl\n"));
	
	close(fd);
	close(fd3);

	return 0;
}
