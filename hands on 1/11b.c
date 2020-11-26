/*Author: Sravya. M (MT2019114)
newfd = dup2(oldfd,newfd);
It will close the file pointed by newfd and keeps the same fd which points to old file now
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

int main()
{
	int fd=open("11test.txt",O_RDWR | O_APPEND,0744);
	int fd2=open("10test.txt",O_RDWR,0744);

	printf("%d ",fd);  		// 11test.txt
	printf("%d ",fd2);		// 10test.txt using dup2
	
	fd2=dup2(fd,fd2);		// duping fd2 to fd

// writing into different file descriptors (which are pointing to the same file
	write(fd, "base\n", strlen("base\n"));
	write(fd2, "dup2\n", strlen("dup2\n"));

	close(fd);
	close(fd2);
	
	return 0;
}
