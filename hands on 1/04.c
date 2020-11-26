/* MT2019114
open an existing file in read write mode (use O_EXCL)
if O_EXCL is used in conjunction with O_CREAT, and pathname already exists, then open fails with the error EEXIST
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
	int fd=open("3test.txt",O_RDWR|O_CREAT|O_EXCL,0744);
	printf("%d\n",fd);
	return 0;
}
