/* MT2019114
create a file and print the fd value
It will return the least unused file descriptor in the table (3)
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
	int fd=creat("3test.txt",0744);
	printf("%d\n",fd);
	return 0;
}
