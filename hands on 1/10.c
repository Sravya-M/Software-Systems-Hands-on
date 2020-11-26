/*Author: Sravya. M (MT2019114)
Program to check a. return value of lseek(fd,bytes,flag), which moves the pointer, b. open destination file using od command (octal dump) for empty spaces
od -c destfile
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
	int fd=open("10test.txt",O_RDWR|O_CREAT,0744);
	int fd1=open("09.c",O_RDONLY);
	char c[10]="helloworld";
	int ret;

	write(fd,&c,10);
	ret=lseek(fd,10,SEEK_CUR);
	write(fd,&c,10);

// lseek returns the current position in file it is pointing to (Here it is 20)
	printf("%d",ret);

	return 0;
}
