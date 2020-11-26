/*Author: Sravya. M (MT2019114)
newfd = dup(oldfd);
Assigns newfd with the least unused file descriptor in the file descriptor table
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

int main()
{
	int fd=open("11test.txt",O_RDWR | O_APPEND,0744);
	int fd1=dup(fd);

	printf("%d ",fd);  		// 11test.txt
	printf("%d ",fd1);		// 11test.txt using dup

// writing into different file descriptors (which are pointing to the same file)
	write(fd, "base\n", strlen("base\n"));
	write(fd1, "dup\n", strlen("dup\n"));

	close(fd);
	close(fd1);
	
	return 0;
}
