/*Author: Sravya. M (MT2019114)
to find out the opening mode of a file
return value of fcntl for the access modes
32768 for O_RDONLY
32769 for O_WRONLY
32770 for O_RDWR
bitwise AND with O_ACCMODE to get 0,1,2 respectively
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
	int mode;
	int fd=open("10test.txt",O_WRONLY|O_CREAT,0744);

	mode = fcntl(fd,F_GETFL);
	mode = mode & O_ACCMODE;

	printf("Access mode is ");
	if(mode==O_WRONLY)
		printf("write only");
	else if(mode==O_RDONLY)
		printf("read only");
	else if(mode==O_RDWR)
		printf("read write");
	else
		printf("ERROR: please check");

	close(fd);
	return 0;
}
