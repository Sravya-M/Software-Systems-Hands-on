/*MT2019114
program to open a file and write from parent and child
*/

#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<sys/types.h>

int main()
{
	int fd=open("22.txt",O_CREAT|O_TRUNC|O_RDWR,0744);
	pid_t pid=fork();

	if(pid==0)
		write(fd,"CHILD\n",strlen("CHILD\n"));
	else
		write(fd,"parent\n",strlen("parent\n"));

	close(fd);
	return 0;
}
